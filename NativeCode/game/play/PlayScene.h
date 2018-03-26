//
//  PlayScene.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 09.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include <list>
#include <vector>
#include <memory>
#include <functional>
#include "GameScene.h"

namespace graphics { namespace node { class Scene; }}
namespace game { namespace node { class Number; }}

namespace game {
namespace play {
	
	class Column;
	
	class PlayScene: public GameScene {
		
	public:
		PlayScene(graphics::node::Scene *scene);
		~PlayScene();
		
		void lifecycle(float dt) override;
		void click() override;
		
		void setGameOverHandler(const std::function <void(int)> handler) { gameOverHandler = handler; }

	private:
		void generateNewColumn();
		void checkCollisions();
		
	private:
		std::unique_ptr <class Bird> bird;
		std::list <std::unique_ptr <Column> > columns;

		std::vector <std::unique_ptr <class Background> > backgrounds;
		
		std::list <std::unique_ptr <Column> >::iterator currentObstacle;
		
		int score;
		std::shared_ptr <node::Number> scoreNumber;
		
		std::function <void(int)> gameOverHandler;
	};
	
}}
