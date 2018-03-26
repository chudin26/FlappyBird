//
//  Size.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 06.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

namespace math {
	
	template <typename T> struct Size {
		
		T width, height;
		
		Size(const T& width, const T& height): width(width), height(height) {}
		
	};
	
	typedef Size <float> SizeFloat;
	
}
