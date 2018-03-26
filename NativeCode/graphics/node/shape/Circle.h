//
//  Circle.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 09.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include "Shape.h"

namespace graphics {
namespace node {
namespace shape {
			
	class Circle: public Shape {
		
	public:
		Circle(hardware::Hardware *hardware, float radius, size_t verticesCount = 50);
		virtual ~Circle();
		
	private:
		float radius;
		
	};
	
}}}
