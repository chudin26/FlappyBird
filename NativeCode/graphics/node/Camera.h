//
//  Camera.hpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 07.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include "Object2D.h"

namespace graphics {
namespace node {
	
	class Camera: public Object2D {

	public:
		Camera(hardware::Hardware *hardware, const math::SizeFloat &size);

		DEFINE_PROPERTY(projectionMatrix, math::Matrix, getProjectionMatrix, setProjectionMatrix, { projectionMatrix = val; })
		
		virtual ~Camera();
		
		virtual void render() override;

		virtual math::Matrix getMatrix() const override;
		
		math::RectFloat getBounds(float z) const;
		
		math::Vec3f convertScreenToWorld(const math::Vec2f &screenPos, float z) const;
		
	private:
		math::SizeFloat size;
		
	};
	
}}
