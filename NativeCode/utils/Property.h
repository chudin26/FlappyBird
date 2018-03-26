//
//  Property.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 29.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#define DEFINE_PROPERTY(name, type, getter, setter, setterBody) \
	private: \
		type name; \
	public: \
		const type& getter() const { return name; } \
		void setter(const type &val) setterBody;
