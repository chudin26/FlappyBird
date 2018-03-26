//
//  Scene.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 29.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include <vector>
#include "Object2D.h"
#include "utils/Property.h"
#include "graphics/Color.h"
#include "math/Matrix.h"

namespace graphics {
namespace node {
	
	class Camera;
	
	class Scene: public Object2D {
	public:
		Scene(hardware::Hardware *hardware, const math::SizeFloat &size);
		virtual ~Scene() override;
		
		DEFINE_PROPERTY(clearColor, Color, getClearColor, setClearColor, { clearColor = val; })
		
		Camera* getCamera() { return camera.get(); }
		
		void render() override;

		void clear();
		void addObject(const std::shared_ptr <Object2D> &obj);
		void removeObject(const std::shared_ptr <Object2D> &obj);
		
		Object2D* getObject(const size_t &index);
		
	private:
		std::vector <Object2DPtr> objects;
		
		std::unique_ptr <Camera> camera;
	};
	
}}
