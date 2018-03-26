//
//  Vertex.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 06.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "Vertex.h"
#include <cstring>

namespace graphics {

Vertex::Vertex() {
	position[0] = 0.0f;
	position[1] = 0.0f;
	position[2] = 0.0f;
}
	
Vertex::Vertex(const math::Vec2f& pos, float zPosition) {
	position[0] = pos.x;
	position[1] = pos.y;
	position[2] = zPosition;
}

}
