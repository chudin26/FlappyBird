//
//  Camera.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 07.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "Camera.h"
#include "graphics/hardware/Hardware.h"

namespace graphics {
namespace node {

Camera::Camera(hardware::Hardware *hardware, const math::SizeFloat &size)
	: Object2D(hardware)
	, size(size)
{
	float h = 2 * size.height / size.width;
	auto projection = math::Matrix::frustum(-2.0f, 2.0f, -h, h, 1, 10);
	setProjectionMatrix(projection);
}
	
Camera::~Camera() {}

math::Matrix Camera::getMatrix() const {
	auto matrix = Object2D::getMatrix();
	matrix.m[12] = -matrix.m[12];
	matrix.m[13] = -matrix.m[13];
	
	return matrix;
}

math::RectFloat Camera::getBounds(float z) const {
	auto leftBottom = convertScreenToWorld( { -1, -1 }, z);
	auto rightTop = convertScreenToWorld( { 1, 1 }, z);
	return { leftBottom.x, leftBottom.y, rightTop.x - leftBottom.x, rightTop.y - leftBottom.y };
}
	
void Camera::render() {
	getHardware()->setupViewport(size);
	getHardware()->setupProjectionMatrix(projectionMatrix);
	getHardware()->setupViewMatrix(getMatrix());
}
	
math::Vec3f Camera::convertScreenToWorld(const math::Vec2f &screenPos, float z) const {
	auto mat = (getMatrix() * projectionMatrix).inverse();
	auto p1 = math::Vec3f(screenPos.x, screenPos.y, 1.0f) * mat;
	auto p2 = math::Vec3f(screenPos.x, screenPos.y, 500.0f) * mat;
	
	float coef = (z - p1.z) / (p2.z - p1.z);
	auto p = p1 + (p2 - p1) * coef;
	
	return p;
}

}}
