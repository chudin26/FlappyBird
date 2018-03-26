//
//  Hardware.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 24.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include "graphics/Color.h"
#include "math/Size.h"
#include "math/Matrix.h"

namespace graphics {
namespace hardware {
	
	class VertexBuffer;
	
	class Hardware {
	public:
		virtual ~Hardware() {}

		virtual void clearBuffer(const Color &clearColor) = 0;
		virtual void setupViewport(const math::SizeFloat &size) = 0;
		virtual void setupShaders() = 0;
		
		virtual void setupProjectionMatrix(const math::Matrix &matrix) = 0;
		virtual void setupViewMatrix(const math::Matrix &matrix) = 0;
		virtual void setupModelMatrix(const math::Matrix &matrix) = 0;
		virtual void setupColor(const Color &color) = 0;
		
		virtual void flipBuffers() = 0;
		
		virtual void drawTriangles(VertexBuffer *vertexBuffer) = 0;
		
		virtual VertexBuffer* createVertexBuffer(size_t verticesCount, size_t trianglesCount) = 0;
	
	};

}}
