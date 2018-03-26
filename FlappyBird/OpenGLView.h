//
//  OpenGLView.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 22.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface OpenGLView : UIView

@property (nonatomic, strong) EAGLContext *context;

- (GLuint)compileShader:(NSString*)shaderName withType:(GLenum)shaderType;

@end
