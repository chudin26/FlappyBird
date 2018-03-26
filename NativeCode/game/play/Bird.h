//
//  Bird.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 09.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include <memory>
#include "math/Rect.h"

namespace graphics { namespace node { class Scene; }}
namespace graphics { namespace node { namespace shape { class Circle; }}}

namespace game {
namespace play {
	
	class Bird {
		
	public:
		Bird(graphics::node::Scene *scene);
		
		void lifecycle(float dt);
		void jump();
		void crash();
		
		const math::Vec2f& getPos() const { return pos; }
		float getRadius() const;
		
		bool intersects(const math::RectFloat &bounds);
		bool intersects(const class Column &column);
		bool pass(const Column &column);
		
	private:
		graphics::node::Scene *scene;
		std::shared_ptr <graphics::node::shape::Circle> circle;
		
	private:
		math::Vec2f pos;
		float velocityY;
		
	};
	
}}
