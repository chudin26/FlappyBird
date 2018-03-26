//
//  Vec3.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 22.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

namespace math {
	
	template <typename T> struct Vec3 {
		T x, y, z;
		
		Vec3(const T& x, const T& y, const T& z): x(x), y(y), z(z) {}

		Vec3 <T> operator + (const Vec3 <T> &v) const {
			return Vec3(x + v.x, y + v.y, z + v.z);
		}
		
		Vec3 <T> operator - (const Vec3 <T> &v) const {
			return Vec3(x - v.x, y - v.y, z - v.z);
		}
		
		Vec3 <T> operator * (float value) const {
			return Vec3(x * value, y * value, z * value);
		}
	};
	
	typedef Vec3 <float> Vec3f;
	
}
