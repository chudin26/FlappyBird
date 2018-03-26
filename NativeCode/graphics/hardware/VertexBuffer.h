//
//  VertexBuffer.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 06.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include <vector>
#include "graphics/Vertex.h"

namespace graphics {
namespace hardware {
	
	class Hardware;
	
	class VertexBuffer {
		
	public:		
		typedef unsigned short Index;
		
		VertexBuffer(Hardware *hardware, size_t verticesCount, size_t trianglesCount);
		virtual ~VertexBuffer();
		
		virtual void fillVertices(const std::vector <Vertex> &vertices);
		virtual void fillIndices(const std::vector <Index> &indices);
		
		size_t indicesCount();
		
		virtual void bind() = 0;
		
	protected:
		std::vector <Vertex> vertices;
		std::vector <Index> indices;
		
		Hardware *hardware;
		
	};
	
}}
