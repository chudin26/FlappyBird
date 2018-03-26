//
//  VertexBufferIOS.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 06.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include "graphics/hardware/VertexBuffer.h"
#include <OpenGLES/gltypes.h>

namespace graphics {
namespace hardware {
		
	class VertexBufferIOS: public VertexBuffer {
	public:
		VertexBufferIOS(Hardware *hardware, size_t verticesCount, size_t trianglesCount);
		virtual ~VertexBufferIOS() override;
		
		virtual void fillVertices(const std::vector <Vertex> &vertices) override;
		virtual void fillIndices(const std::vector <Index> &indices) override;
		
		virtual void bind() override;
		
	private:
		GLuint vertexBuffer;
		GLuint indexBuffer;
		
	};
		
}}
