//
//  Scene.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 29.11.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "Scene.h"
#include "Camera.h"
#include "graphics/hardware/Hardware.h"

namespace graphics {
namespace node {
	
Scene::Scene(hardware::Hardware *hardware, const math::SizeFloat &size)
	: Object2D(hardware)
	, camera(new Camera(hardware, size))
{
}

Scene::~Scene() {
	
}

void Scene::render() {
	getHardware()->clearBuffer(clearColor);
	
	camera->render();
	
	auto sortedObjects = objects;
	std::sort(sortedObjects.begin(), sortedObjects.end(), [](const Object2DPtr &a, const Object2DPtr &b) -> bool {
		return a->getZPosition() < b->getZPosition();
	});
	
	for (auto const &obj: sortedObjects) {
		obj->render();
	}
}
	
void Scene::clear() {
	objects.clear();
}
	
void Scene::addObject(const std::shared_ptr <Object2D> &obj) {
	objects.push_back(obj);
}

void Scene::removeObject(const std::shared_ptr <Object2D> &obj) {
	auto it = std::find(objects.begin(), objects.end(), obj);
	if (it != objects.end())
		objects.erase(it);
}

Object2D* Scene::getObject(const size_t &index) {
	if (index >= objects.size())
		return nullptr;
	
	return objects[index].get();
}

}}
