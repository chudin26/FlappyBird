//
//  Vec2.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 22.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include <math.h>

namespace math {
	
	template <typename T> struct Vec2 {
		T x, y;
		
		Vec2(const T& x, const T& y): x(x), y(y) {}
		
		T length() const {
			return sqrt(x * x + y * y);
		}
		
		Vec2 <T> operator + (const Vec2 <T> &v) const {
			return Vec2(x + v.x, y + v.y);
		}

		Vec2 <T> operator - (const Vec2 <T> &v) const {
			return Vec2(x - v.x, y - v.y);
		}
		
		static Vec2 <T> zero() { return Vec2 <T> (0, 0); }
	};
	
	typedef Vec2 <float> Vec2f;
	
}
