//
//  FlappyBirdApplication.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 05.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include "game/Application.h"

namespace game {
	
	class GameScene;
	
	class FlappyBirdApplication: public Application {
		
	public:
		FlappyBirdApplication(graphics::hardware::Hardware *hardware, const math::SizeFloat &size);
		~FlappyBirdApplication();
		
	protected:
		void lifecycle(float deltaTime) override;

		void touchBegan(const math::Vec2f &pos) override;

	private:
		void restart();
		
		std::unique_ptr <GameScene> gameScene;
		
	};

}
