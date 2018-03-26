//
//  Application.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 02.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include <memory>
#include "math/Rect.h"

namespace graphics { namespace hardware { class Hardware; }}
namespace graphics { namespace node { class Scene; }}

namespace game {
	
	class Application {
	public:
		Application(graphics::hardware::Hardware *hardware, const math::SizeFloat &size);
		virtual ~Application();
		
		static Application* getInstance();
		
		virtual void lifecycle(float deltaTime) = 0;
		virtual void render();

		graphics::node::Scene* getScene() const { return scene.get(); }
		void setScene(graphics::node::Scene *scene);
		
		virtual void touchBegan(const math::Vec2f &pos) {}
		virtual void touchMoved(const math::Vec2f &pos) {}
		virtual void touchEnded(const math::Vec2f &pos) {}
		
		graphics::hardware::Hardware* getHardware() const { return hardware.get(); }
		
	private:
		std::unique_ptr <graphics::hardware::Hardware> hardware;
		std::unique_ptr <graphics::node::Scene> scene;
		
	};
	
}
