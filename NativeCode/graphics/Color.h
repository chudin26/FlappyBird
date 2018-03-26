//
//  Color.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 29.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

namespace graphics {
	
	struct Color {

		typedef float Float;
		
		Float component[4];
		
		Color() {}
		Color(const Float &r, const Float &g, const Float &b, const Float &a = 1.0);
		
		const Float& getRed() const { return component[0]; }
		const Float& getGreen() const { return component[1]; }
		const Float& getBlue() const { return component[2]; }
		const Float& getAlpha() const { return component[3]; }
		
		void setRed(const Float &value) { component[0] = value; }
		void setGreen(const Float &value) { component[1] = value; }
		void setBlue(const Float &value) { component[2] = value; }
		void setAlpha(const Float &value) { component[3] = value; }
		
		static Color interpolate(const Color &color1, const Color &color2, float coefficient);
		
		// Colors
		static Color white();
		static Color black();
		static Color red();
		static Color green();
		static Color blue();
	};
	
}
