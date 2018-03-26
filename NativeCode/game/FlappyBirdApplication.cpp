//
//  FlappyBirdApplication.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 05.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "FlappyBirdApplication.h"
#include "play/PlayScene.h"
#include "TryAgainScene.h"
#include "graphics/node/Scene.h"
#include "graphics/node/Camera.h"
#include "graphics/node/shape/Rectangle.h"

using namespace graphics::node::shape;

namespace game {

FlappyBirdApplication::FlappyBirdApplication(graphics::hardware::Hardware *hardware, const math::SizeFloat &size)
	: game::Application(hardware, size)
{
	getScene()->setClearColor(graphics::Color(0.4f, 0.8f, 1.0f));
	
	restart();
}
	
FlappyBirdApplication::~FlappyBirdApplication() {}

void FlappyBirdApplication::lifecycle(float deltaTime) {
	gameScene->lifecycle(deltaTime);
}

void FlappyBirdApplication::touchBegan(const math::Vec2f &pos) {
	gameScene->click();
}

void FlappyBirdApplication::restart() {
	getScene()->clear();

	auto playScene = new play::PlayScene(getScene());
	playScene->setGameOverHandler( [this](int score) {
		auto tryAgainScene = new TryAgainScene(getScene(), score);
		tryAgainScene->setClickHandler( [this]() { this->restart(); } );
		
		gameScene.reset(tryAgainScene);
	} );
	
	gameScene.reset(playScene);
}
	
}
