//
//  Object2D.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 22.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include <memory>
#include "utils/Property.h"
#include "math/Rect.h"
#include "math/Matrix.h"

namespace graphics { namespace hardware { class Hardware; }}

namespace graphics {
namespace node {
	
	class Object2D {
	public:
		Object2D(hardware::Hardware *hardware);
		virtual ~Object2D();
		
		virtual void render() = 0;
		
		DEFINE_PROPERTY(position, math::Vec2f, getPosition, setPosition, { position = val; })
		DEFINE_PROPERTY(zPosition, float, getZPosition, setZPosition, { zPosition = val; })
		DEFINE_PROPERTY(rotation, float, getRotation, setRotation, { rotation = val; })
		DEFINE_PROPERTY(scale, math::Vec2f, getScale, setScale, { scale = val; })
		
		virtual math::Matrix getMatrix() const;
		
		hardware::Hardware* getHardware() const { return hardware; }
		
	private:
		hardware::Hardware *hardware;
	
	};
	
	typedef std::shared_ptr <Object2D> Object2DPtr;
	
}}
