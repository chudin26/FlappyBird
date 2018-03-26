//
//  Column.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 09.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include <memory>
#include <vector>
#include "math/Rect.h"

namespace graphics { namespace node { class Scene; }}
namespace graphics { namespace node { namespace shape { class Rectangle; }}}

namespace game {
namespace play {
	
	class Bird;
	
	class Column {
		
	public:
		Column(graphics::node::Scene *scene, float pos);
		Column(const Column &other) = delete;
		~Column();

		float getWidth() const;
		float getRight() const;
		
		std::vector <math::RectFloat> getRects() const;
		
		void removeFromScene();
		
	private:
		graphics::node::Scene *scene;
		std::shared_ptr <graphics::node::shape::Rectangle> rectangles[2];
		
	};
		
}}
