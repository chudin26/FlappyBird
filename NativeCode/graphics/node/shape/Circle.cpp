//
//  Circle.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 09.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "Circle.h"

#include "graphics/hardware/Hardware.h"
#include "graphics/hardware/VertexBuffer.h"

namespace graphics {
namespace node {
namespace shape {
			
Circle::Circle(hardware::Hardware *hardware, float radius, size_t verticesCount)
	: Shape(hardware)
	, radius(radius)
{
	vertexBuffer.reset(hardware->createVertexBuffer(verticesCount + 1, verticesCount));
	
	std::vector <Vertex> vertices(verticesCount + 1);
	std::vector <hardware::VertexBuffer::Index> indices(verticesCount * 3);
	
	vertices[0] = Vertex();
	for (size_t i = 0; i < verticesCount; i++) {
		const float angle = i / (float) verticesCount * M_PI * 2;
		const float x = radius * sinf(angle);
		const float y = radius * cosf(angle);
		vertices[i + 1] = Vertex(math::Vec2f(x, y), 0.0f);
		
		indices[i * 3 + 0] = 0;
		indices[i * 3 + 1] = i + 1;
		indices[i * 3 + 2] = i + 2;
	}
	
	indices[indices.size() - 1] = 1;
	
	vertexBuffer->fillVertices(vertices);
	vertexBuffer->fillIndices(indices);
}

Circle::~Circle() {}

}}}
