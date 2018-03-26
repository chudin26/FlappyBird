//
//  HardwareIOS.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 30.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include "graphics/hardware/Hardware.h"
#import "OpenGLView.h"

namespace graphics {
namespace hardware {

	class HardwareIOS: public Hardware {
		
	public:
		HardwareIOS(OpenGLView *glView);
		virtual ~HardwareIOS() override;
		
		virtual void clearBuffer(const Color &clearColor) override;
		virtual void setupViewport(const math::SizeFloat &size) override;
		virtual void setupShaders() override;
		
		virtual void setupProjectionMatrix(const math::Matrix &matrix) override;
		virtual void setupViewMatrix(const math::Matrix &matrix) override;
		virtual void setupModelMatrix(const math::Matrix &matrix) override;
		virtual void setupColor(const Color &color) override;
		
		virtual void flipBuffers() override;
		
		virtual void drawTriangles(VertexBuffer *vertexBuffer) override;
		
		virtual VertexBuffer* createVertexBuffer(size_t verticesCount, size_t trianglesCount) override;
		
	private:
		OpenGLView *glView;
		
		void compileShaders();
		
		// Shader variables
		GLuint positionSlot;
		
		GLuint colorUniform;
		GLuint projectionUniform;
		GLuint viewUniform;
		GLuint modelUniform;
	};
	
}}
