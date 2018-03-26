//
//  Rectangle.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 06.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "Rectangle.h"
#include "graphics/hardware/Hardware.h"
#include "graphics/hardware/VertexBuffer.h"

namespace graphics {
namespace node {
namespace shape {

Rectangle::Rectangle(hardware::Hardware *hardware, const math::RectFloat &rect)
	: Shape(hardware)
	, rect(rect)
{
	vertexBuffer.reset(hardware->createVertexBuffer(4, 2));
	
	vertexBuffer->fillVertices( {
		Vertex(rect.leftBottom(), 0.0f),
		Vertex(rect.leftTop(), 0.0f),
		Vertex(rect.rightTop(), 0.0f),
		Vertex(rect.rightBottom(), 0.0f)
	} );
	
	vertexBuffer->fillIndices( { 0, 1, 2, 2, 3, 0 } );
}

Rectangle::~Rectangle() {}
	
math::RectFloat Rectangle::getBounds() const {
	return rect.shift(getPosition());
}

}}}
