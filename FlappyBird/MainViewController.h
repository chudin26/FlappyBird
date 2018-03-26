//
//  MainViewController.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 22.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#import <UIKit/UIKit.h>

@class OpenGLView;

@interface MainViewController : UIViewController

@property (nonatomic, readonly) OpenGLView *glView;

@end
