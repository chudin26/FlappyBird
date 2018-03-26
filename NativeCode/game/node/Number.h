//
//  Number.hpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 08.01.17.
//  Copyright © 2017 Yuriy Chudin. All rights reserved.
//

#pragma once

#include "graphics/node/shape/Shape.h"

namespace game {
namespace node {
		
	class Number: public graphics::node::shape::Shape {
		
	public:
		Number(graphics::hardware::Hardware *hardware, unsigned int value);
		virtual ~Number() override;
		
		DEFINE_PROPERTY(value, unsigned int, getValue, setValue,;)
		
	private:
		void rebuild();
		
	};
	
}}
