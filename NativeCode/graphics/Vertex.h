//
//  Vertex.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 06.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include "math/Vec2.h"
#include "graphics/Color.h"

namespace graphics {
	
	struct Vertex {
		
		float position[3];
		
		Vertex();
		Vertex(const math::Vec2f& pos, float zPosition);
		
	};
	
}
