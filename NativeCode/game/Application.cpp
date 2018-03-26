//
//  Application.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 02.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "Application.h"
#include "graphics/hardware/Hardware.h"
#include "graphics/node/Scene.h"

namespace game {

static Application *instance = NULL;

Application::Application(graphics::hardware::Hardware *hardware, const math::SizeFloat &size)
	: hardware(hardware)
	, scene(new graphics::node::Scene(hardware, size))
{
	instance = this;
}

Application::~Application() {}
	
Application* Application::getInstance() {
	return instance;
}
	
void Application::render() {
	scene->render();
	
	hardware->flipBuffers();
}

void Application::setScene(graphics::node::Scene *scene) {
	this->scene.reset(scene);
}

}
