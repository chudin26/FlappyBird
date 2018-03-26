//
//  GameScene.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 09.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

namespace graphics { namespace node { class Scene; }}

namespace game {
	
	class GameScene {
		
	public:
		GameScene(graphics::node::Scene *scene);
		virtual ~GameScene();

		virtual void lifecycle(float dt) = 0;
		virtual void click() = 0;
		
	protected:
		graphics::node::Scene* getScene() const { return scene; }
		
	private:
		graphics::node::Scene *scene;
		
	};
	
}
