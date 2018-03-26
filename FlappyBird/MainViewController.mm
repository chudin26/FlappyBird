//
//  MainViewController.m
//  FlappyBird
//
//  Created by Yuriy Chudin on 22.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#import "MainViewController.h"
#import "OpenGLView.h"
#import "HardwareIOS.h"
#include "FlappyBirdApplication.h"

@interface MainViewController () {
	NSTimer *timer;
	double lastTime;
	
	std::unique_ptr <game::Application> application;
}

@end


@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	CGSize screenSize = [UIScreen mainScreen].bounds.size;
	CGFloat scale = [[UIScreen mainScreen] scale];
	auto size = math::SizeFloat(screenSize.width * scale, screenSize.height * scale);
	
	auto hardware = new graphics::hardware::HardwareIOS(self.glView);
	application.reset(new game::FlappyBirdApplication(hardware, size));
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	application->render();
	
	[self startAnimating];
}

- (void)viewWillDisappear:(BOOL)animated {
	[super viewWillDisappear:animated];
	
	[self stopAnimating];
}

- (void)startAnimating {
	CGFloat interval = 1.0 / 60.0f;
	lastTime = [[NSDate date] timeIntervalSince1970];
	timer = [NSTimer scheduledTimerWithTimeInterval:interval target:self selector:@selector(onTimer) userInfo:nil repeats:YES];
}

- (void)stopAnimating {
	[timer invalidate];
	timer = nil;
}

- (void)onTimer {
	double currentTime = [[NSDate date] timeIntervalSince1970];
	CGFloat dt = currentTime - lastTime;
	if (dt > 0.2f)
		dt = 0.2f;
	
	application->lifecycle(dt);
	application->render();
	
	lastTime = currentTime;
}

- (OpenGLView *)glView {
	return (OpenGLView *)self.view;
}

@end
