//
//  HardwareIOS.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 30.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#import "HardwareIOS.h"
#include "VertexBufferIOS.h"
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

namespace graphics {
namespace hardware {

HardwareIOS::HardwareIOS(OpenGLView *glView)
	: glView(glView)
{
	compileShaders();
}

HardwareIOS::~HardwareIOS() {
	
}
	
void HardwareIOS::compileShaders() {
	GLuint vertexShader = [glView compileShader:@"SimpleVertex" withType:GL_VERTEX_SHADER];
	GLuint fragmentShader = [glView compileShader:@"SimpleFragment" withType:GL_FRAGMENT_SHADER];
	
	GLuint programHandle = glCreateProgram();
	glAttachShader(programHandle, vertexShader);
	glAttachShader(programHandle, fragmentShader);
	glLinkProgram(programHandle);
	
	GLint linkSuccess;
	glGetProgramiv(programHandle, GL_LINK_STATUS, &linkSuccess);
	if (linkSuccess == GL_FALSE) {
		GLchar messages[256];
		glGetProgramInfoLog(programHandle, sizeof(messages), 0, &messages[0]);
		NSString *messageString = [NSString stringWithUTF8String:messages];
		NSLog(@"%@", messageString);
		exit(1);
	}
 
	glUseProgram(programHandle);
 
	positionSlot = glGetAttribLocation(programHandle, "Position");
	glEnableVertexAttribArray(positionSlot);
	
	projectionUniform = glGetUniformLocation(programHandle, "Projection");	
	modelUniform = glGetUniformLocation(programHandle, "Model");
	viewUniform = glGetUniformLocation(programHandle, "View");
	colorUniform = glGetUniformLocation(programHandle, "Color");
}

void HardwareIOS::clearBuffer(const graphics::Color &clearColor) {
	glClearColor(clearColor.getRed(), clearColor.getGreen(), clearColor.getBlue(), 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
}
	
void HardwareIOS::setupViewport(const math::SizeFloat &size) {
	glViewport(0, 0, size.width, size.height);
}

void HardwareIOS::setupProjectionMatrix(const math::Matrix &matrix) {
	glUniformMatrix4fv(projectionUniform, 1, 0, matrix.m);
}
	
void HardwareIOS::setupModelMatrix(const math::Matrix &matrix) {
	glUniformMatrix4fv(modelUniform, 1, 0, matrix.m);
}

void HardwareIOS::setupViewMatrix(const math::Matrix &matrix) {
	glUniformMatrix4fv(viewUniform, 1, 0, matrix.m);
}

void HardwareIOS::setupShaders() {
	glEnableVertexAttribArray(positionSlot);
	glVertexAttribPointer(positionSlot, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
}
	
void HardwareIOS::setupColor(const graphics::Color &color) {
	glUniform4fv(colorUniform, 1, color.component);
}

void HardwareIOS::flipBuffers() {
	[glView.context presentRenderbuffer:GL_RENDERBUFFER];
}
	
void HardwareIOS::drawTriangles(VertexBuffer *vertexBuffer) {
	glDrawElements(GL_TRIANGLES, (GLsizei) vertexBuffer->indicesCount(), GL_UNSIGNED_SHORT, 0);
}

VertexBuffer* HardwareIOS::createVertexBuffer(size_t verticesCount, size_t trianglesCount) {
	return new VertexBufferIOS(this, verticesCount, trianglesCount);
}

}}
