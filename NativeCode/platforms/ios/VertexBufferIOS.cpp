//
//  VertexBufferIOS.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 06.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "VertexBufferIOS.h"
#include "Hardware.h"
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

namespace graphics {
namespace hardware {
	
VertexBufferIOS::VertexBufferIOS(Hardware *hardware, size_t verticesCount, size_t trianglesCount)
	: VertexBuffer(hardware, verticesCount, trianglesCount)
{
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * verticesCount, &vertices[0], GL_STATIC_DRAW);
 	
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Index) * trianglesCount * 3, &indices[0], GL_STATIC_DRAW);
}

VertexBufferIOS::~VertexBufferIOS() {}

void VertexBufferIOS::fillVertices(const std::vector <Vertex> &vertices) {
	VertexBuffer::fillVertices(vertices);
	
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
}

void VertexBufferIOS::fillIndices(const std::vector <Index> &indices) {
	VertexBuffer::fillIndices(indices);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Index) * indices.size(), &indices[0], GL_STATIC_DRAW);
}

void VertexBufferIOS::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
}
	
}}
