//
//  Color.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 29.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "Color.h"
#include <algorithm>

namespace graphics {
	
Color::Color(const Float &r, const Float &g, const Float &b, const Float &a) {
	component[0] = r;
	component[1] = g;
	component[2] = b;
	component[3] = a;
}

Color Color::interpolate(const Color &color1, const Color &color2, float coefficient) {
	Color result;
	
	for (int i = 0; i < 4; i++) {
		Float value = color1.component[i] + (color2.component[i] - color1.component[i]) * coefficient;
		result.component[i] = std::max((Float) 0.0, std::min((Float) 1.0, value));
	}
	
	return result;
}

Color Color::white() { return Color(1.0f, 1.0f, 1.0f); }
Color Color::black() { return Color(0.0f, 0.0f, 0.0f); }
Color Color::red() { return Color(1.0f, 0.0f, 0.0f); }
Color Color::green() { return Color(0.0f, 1.0f, 0.0f); }
Color Color::blue() { return Color(0.0f, 0.0f, 1.0f); }
	
}
