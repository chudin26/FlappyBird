//
//  TryAgainScene.hpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 09.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include "GameScene.h"
#include <functional>

namespace game {
	
	class TryAgainScene: public GameScene {
		
	public:
		TryAgainScene(graphics::node::Scene *scene, int score);
		~TryAgainScene();
	
		void lifecycle(float dt) override {}
		void click() override;
		
		void setClickHandler(const std::function <void()> &handler) { clickHandler = handler; }

	private:
		std::function <void()> clickHandler;
		
	};
	
}
