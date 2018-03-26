//
//  OpenGLView.m
//  FlappyBird
//
//  Created by Yuriy Chudin on 22.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#import "OpenGLView.h"
#import <QuartzCore/QuartzCore.h>
#import "HardwareIOS.h"
#include "game/Application.h"
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

#define THROW_ERROR(error) NSLog(error); exit(1);
#define THROW_ERROR_FORMAT(format, description) NSLog(format, description); exit(1);

@interface OpenGLView() {
	GLuint colorRenderBuffer;
}

@property (nonatomic, readonly) CAEAGLLayer *eaglLayer;

@end


@implementation OpenGLView

- (id)initWithCoder:(NSCoder *)aDecoder {
	if (self = [super initWithCoder:aDecoder]) {
		[self setup];
	}
	
	return self;
}

- (GLuint)compileShader:(NSString*)shaderName withType:(GLenum)shaderType {
	NSString* shaderPath = [[NSBundle mainBundle] pathForResource:shaderName ofType:@"glsl"];
	NSError* error;
	NSString* shaderString = [NSString stringWithContentsOfFile:shaderPath encoding:NSUTF8StringEncoding error:&error];
	if (!shaderString) {
		THROW_ERROR_FORMAT(@"Error loading shader: %@", error.localizedDescription);
	}
 
	GLuint shaderHandle = glCreateShader(shaderType);
 
	const char * shaderStringUTF8 = [shaderString UTF8String];
	int shaderStringLength = (int)[shaderString length];
	glShaderSource(shaderHandle, 1, &shaderStringUTF8, &shaderStringLength);
 
	glCompileShader(shaderHandle);
 
	GLint compileSuccess;
	glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &compileSuccess);
	if (compileSuccess == GL_FALSE) {
		GLchar messages[256];
		glGetShaderInfoLog(shaderHandle, sizeof(messages), 0, &messages[0]);
		NSString *messageString = [NSString stringWithUTF8String:messages];
		THROW_ERROR_FORMAT(@"%@", messageString);
	}
 
	return shaderHandle;
}

+ (Class)layerClass {
	return [CAEAGLLayer class];
}

- (CAEAGLLayer *)eaglLayer {
	return (CAEAGLLayer*) self.layer;
}

- (void)setup {
	self.eaglLayer.opaque = YES;
	self.eaglLayer.contentsScale = [[UIScreen mainScreen] scale];

	EAGLRenderingAPI api = kEAGLRenderingAPIOpenGLES2;
	_context = [[EAGLContext alloc] initWithAPI:api];
	if (!_context) {
		THROW_ERROR(@"Failed to initialize OpenGLES 2.0 context");
	}
 
	if (![EAGLContext setCurrentContext:_context]) {
		THROW_ERROR(@"Failed to set current OpenGL context");
	}

	glGenRenderbuffers(1, &colorRenderBuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, colorRenderBuffer);
	[_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:self.eaglLayer];

	GLuint framebuffer;
	glGenFramebuffers(1, &framebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, colorRenderBuffer);
}

- (void)setFrame:(CGRect)frame {
	[super setFrame:frame];
	
	[_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:self.eaglLayer];
}

#pragma mark Touches

static math::Vec2f convertFromTouches(NSSet <UITouch *> *touches, UIView *view) {
	CGFloat scale = [[UIScreen mainScreen] scale];
	
	CGPoint p = [[touches anyObject] locationInView:view];
	p.x = p.x / view.bounds.size.width * scale;
	p.y = p.y / view.bounds.size.height * scale;
	
	return math::Vec2f(p.x, p.y);
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
	game::Application::getInstance()->touchBegan(convertFromTouches(touches, self));
}

- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
	game::Application::getInstance()->touchMoved(convertFromTouches(touches, self));
}

- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
	game::Application::getInstance()->touchEnded(convertFromTouches(touches, self));
}

@end
