//
//  Background.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 09.01.17.
//  Copyright © 2017 Yuriy Chudin. All rights reserved.
//

#pragma once

#include <vector>
#include <memory>
#include "math/Rect.h"
#include "graphics/Color.h"

namespace graphics { namespace node { class Scene; }}
namespace graphics { namespace node { namespace shape { class Rectangle; }}}

namespace game {
namespace play {

	class Background {
	public:
		Background(graphics::node::Scene *scene, const graphics::Color &color, float maxHeight, float z);
		
		void lifecycle(float dt);

	private:
		void generateDecoration(const math::RectFloat &cameraBounds);
		
	private:
		graphics::node::Scene *scene;

		float maxHeight;
		float z;
		graphics::Color color;
		
		std::vector <std::shared_ptr <graphics::node::shape::Rectangle> > decorations;
		
	};
	
}}
