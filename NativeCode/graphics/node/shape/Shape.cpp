//
//  Shape.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 06.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "Shape.h"
#include "VertexBuffer.h"
#include "graphics/hardware/Hardware.h"

namespace graphics {
namespace node {
namespace shape {

Shape::Shape(hardware::Hardware *hardware)
	: Object2D(hardware)
{
}
	
Shape::~Shape() {}

void Shape::render() {
	if (vertexBuffer.get())
		vertexBuffer->bind();
	
	getHardware()->setupShaders();
	getHardware()->setupModelMatrix(getMatrix());
	
	draw();
}

void Shape::draw() const {
	getHardware()->setupColor(color);
	getHardware()->drawTriangles(vertexBuffer.get());
}

}}}
