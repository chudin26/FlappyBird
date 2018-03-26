//
//  TryAgainScene.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 09.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "TryAgainScene.h"
#include "graphics/node/Scene.h"
#include "graphics/node/Camera.h"
#include "graphics/node/shape/Rectangle.h"
#include "game/node/Number.h"
#include "Constants.h"

namespace game {
	
TryAgainScene::TryAgainScene(graphics::node::Scene *scene, int score)
	: GameScene(scene)
{
	auto rectangle = new graphics::node::shape::Rectangle(scene->getHardware(), { -20.0f, -20.0f, 40.0f, 40.0f });
	rectangle->setColor(graphics::Color(0.0f, 0.0f, 0.0f, 0.7f));
	rectangle->setZPosition(MAIN_Z_POSITION + 0.1f);
	rectangle->setPosition(scene->getCamera()->getPosition());
	scene->addObject(std::shared_ptr <graphics::node::Object2D>(rectangle));
	
	auto number = new game::node::Number(scene->getHardware(), score);
	number->setColor(graphics::Color::white());
	number->setZPosition(MAIN_Z_POSITION + 0.2f);
	number->setScale( { 3.0f, 3.0f } );
	number->setPosition(scene->getCamera()->getPosition());
	scene->addObject(std::shared_ptr <graphics::node::Object2D>(number));
}

TryAgainScene::~TryAgainScene() {}

void TryAgainScene::click() {
	if (clickHandler)
		clickHandler();
}

}
