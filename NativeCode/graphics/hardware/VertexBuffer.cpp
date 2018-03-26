//
//  VertexBuffer.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 06.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "VertexBuffer.h"
#include "graphics/Vertex.h"

namespace graphics {
namespace hardware {

VertexBuffer::VertexBuffer(Hardware *hardware, size_t verticesCount, size_t trianglesCount)
	: vertices(verticesCount)
	, indices(trianglesCount * 3)
	, hardware(hardware)
{
}

VertexBuffer::~VertexBuffer() {}
	
void VertexBuffer::fillVertices(const std::vector <Vertex> &vertices) {
	// TODO: make faster copying
	this->vertices = vertices;
}

void VertexBuffer::fillIndices(const std::vector <Index> &indices) {
	// TODO: make faster copying
	this->indices = indices;
}
	
size_t VertexBuffer::indicesCount() {
	return indices.size();
}
	
}}
