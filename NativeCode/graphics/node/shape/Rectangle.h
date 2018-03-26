//
//  Rectangle.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 06.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include "Shape.h"

namespace graphics {
namespace node {
namespace shape {
	
	class Rectangle: public Shape {
		
	public:
		Rectangle(hardware::Hardware *hardware, const math::RectFloat &rect);
		virtual ~Rectangle();

		math::RectFloat getBounds() const;
		
	private:
		math::RectFloat rect;
		
	};

}}}
