//
//  Rect.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 06.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include "Vec2.h"
#include "Size.h"

namespace math {
	
	template <typename T> struct Rect {
		
		T x, y, width, height;
		
		Rect(const T& x, const T& y, const T& width, const T& height): x(x), y(y), width(width), height(height) {}
		Rect(const Vec2 <T>& pos, const Size <T>& size): x(pos.x), y(pos.y), width(size.width), height(size.height) {}
		Rect(const Size <T>& size): x(0), y(0), width(size.width), height(size.height) {}
		
		Vec2 <T> center() const {
			return Vec2 <T> (x + width / 2, y + height / 2);
		}
		
		Size <T> size() const {
			return Size <T> (width, height);
		}
		
		T left() const { return x; }
		T right() const { return x + width; }
		T bottom() const { return y; }
		T top() const { return y + height; }
		
		Vec2 <T> leftBottom() const { return Vec2 <T> (left(), bottom()); }
		Vec2 <T> leftTop() const { return Vec2 <T> (left(), top()); }
		Vec2 <T> rightBottom() const { return Vec2 <T> (right(), bottom()); }
		Vec2 <T> rightTop() const { return Vec2 <T> (right(), top()); }
		
		math::Rect <T> shift(const Vec2 <T>& v) const {
			return math::Rect <T> (x + v.x, y + v.y, width, height);
		}
		
	};
		
	typedef Rect <float> RectFloat;
	
}
