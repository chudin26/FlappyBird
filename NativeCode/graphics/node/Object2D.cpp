//
//  Object2D.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 29.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "Object2D.h"
#include "graphics/hardware/VertexBuffer.h"

namespace graphics {
namespace node {

Object2D::Object2D(hardware::Hardware *hardware)
	: position(0.0f, 0.0f)
	, zPosition(0.0f)
	, rotation(0.0f)
	, scale(1.0f, 1.0f)
	, hardware(hardware)
{
}
	
Object2D::~Object2D() {}
	
math::Matrix Object2D::getMatrix() const {
	auto translationMat = math::Matrix::translation( { position.x, position.y, zPosition } );
	auto scaleMat = math::Matrix::scale( { scale.x, scale.y, 1.0f } );
	return scaleMat * translationMat;
}

}}
