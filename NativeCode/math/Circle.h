//
//  Circle.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 07.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include "Rect.h"

namespace math {

	struct Circle {
		
		Vec2f center;
		float radius;
		
		Circle(const Vec2f &center, float radius): center(center), radius(radius) {}
		
		bool intersect(const Vec2f& point) const {
			return (point - center).length() < radius;
		}
		
		bool intersect(const RectFloat& rect) const {
			if (inBounds(center.y, rect.bottom(), rect.top()) &&
				(inBounds(center.x + radius, rect.left(), rect.right()) ||
				 inBounds(center.x - radius, rect.left(), rect.right())))
				return true;
			
			if (inBounds(center.x, rect.left(), rect.right()) &&
				(inBounds(center.y + radius, rect.bottom(), rect.top()) ||
				 inBounds(center.y - radius, rect.bottom(), rect.top())))
				return true;

			return intersect(rect.leftBottom()) || intersect(rect.leftTop()) ||
					intersect(rect.rightBottom()) || intersect(rect.rightTop());
		}
		
	private:
		bool inBounds(float value, float low, float high) const {
			return value > low && value < high;
		}
		
	};
	
}
