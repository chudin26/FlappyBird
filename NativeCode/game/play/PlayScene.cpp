//
//  PlayScene.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 09.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "PlayScene.h"
#include "Bird.h"
#include "Column.h"
#include "Background.h"
#include "graphics/node/Scene.h"
#include "graphics/node/Camera.h"
#include "game/node/Number.h"
#include "Constants.h"

namespace game {
namespace play {
	
PlayScene::PlayScene(graphics::node::Scene *scene)
	: GameScene(scene)
	, bird(new Bird(scene))
	, currentObstacle(columns.end())
	, score(0)
{
	scoreNumber = std::shared_ptr <node::Number> (new node::Number(scene->getHardware(), 0));
	scoreNumber->setColor(graphics::Color(0.5f, 0.0f, 0.0f));
	scoreNumber->setZPosition(MAIN_Z_POSITION + 0.1f);
	scoreNumber->setScale( { 0.5f, 0.5f } );
	scene->addObject(scoreNumber);

	backgrounds.push_back(std::unique_ptr <Background>(new Background(scene, { 0.7f, 0.77f, 0.75f }, 6.0f, BACKGROUND_Z_POSITION + 5.0f)));
	backgrounds.push_back(std::unique_ptr <Background>(new Background(scene, { 0.82f, 0.83f, 0.89f }, 22.0f, BACKGROUND_Z_POSITION)));
}
	
PlayScene::~PlayScene() {}

void PlayScene::lifecycle(float dt) {
	bird->lifecycle(dt);
	
	// Set camera to bird position
	const float x = bird->getPos().x + 3.0f;
	getScene()->getCamera()->setPosition( { x, 0.0f } );
	
	for (auto &background: backgrounds)
		background->lifecycle(dt);
	
	// Check for need of creating new columns
	const auto cameraBounds = getScene()->getCamera()->getBounds(MAIN_Z_POSITION);
	if (columns.size() == 0 || (cameraBounds.right() - columns.back()->getRight() > COLUMN_DISTANCE)) {
		generateNewColumn();
	}
	
	// Update score number position by camera
	scoreNumber->setPosition(cameraBounds.rightTop() - math::Vec2f(2.0f, 2.0f));
	
	checkCollisions();
}
	
void PlayScene::generateNewColumn() {
	float x = getScene()->getCamera()->getBounds(MAIN_Z_POSITION).right();
	auto column = new Column(getScene(), x + COLUMN_WIDTH);
	columns.emplace_back(column);
	
	if (columns.front()->getRight() < getScene()->getCamera()->getBounds(MAIN_Z_POSITION).left()) {
		columns.front()->removeFromScene();
		columns.erase(columns.begin());
	}
}

void PlayScene::checkCollisions() {
	if (currentObstacle == columns.end()) {
		currentObstacle = columns.begin();
	}
	
	const auto cameraBounds = getScene()->getCamera()->getBounds(MAIN_Z_POSITION);
	if (bird->intersects(*(*currentObstacle).get()) || bird->intersects(cameraBounds)) {
		bird->crash();
		
		gameOverHandler(score);
		return;
	}
	
	while (currentObstacle != columns.end() && bird->pass(*(*currentObstacle).get())) {
		currentObstacle++;
		
		score++;
		scoreNumber->setValue(score);
	}
}

void PlayScene::click() {
	bird->jump();
}
	
}}
