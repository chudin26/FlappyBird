//
//  Shape.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 06.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include "Object2D.h"
#include "utils/Property.h"
#include "graphics/Color.h"

namespace graphics { namespace hardware { class VertexBuffer; }}

namespace graphics {
namespace node {
namespace shape {
		
	class Shape: public Object2D {

	protected:
		std::unique_ptr <hardware::VertexBuffer> vertexBuffer;
		
	public:
		Shape(hardware::Hardware *hardware);
		virtual ~Shape() override;
		
		virtual void render() override;
		virtual void draw() const;
				
		DEFINE_PROPERTY(color, Color, getColor, setColor, { color = val; })
		
	};
	
}}}
