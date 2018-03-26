//
//  Background.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 09.01.17.
//  Copyright © 2017 Yuriy Chudin. All rights reserved.
//

#include "Background.h"
#include "Constants.h"
#include "utils/Random.h"
#include "graphics/node/Scene.h"
#include "graphics/node/Camera.h"
#include "graphics/node/shape/Rectangle.h"

using namespace graphics::node;

namespace game {
namespace play {
	
Background::Background(graphics::node::Scene *scene, const graphics::Color &color, float maxHeight, float z)
	: scene(scene)
	, color(color)
	, maxHeight(maxHeight)
	, z(z)
{
}
	
void Background::lifecycle(float dt) {
	auto cameraBounds = scene->getCamera()->getBounds(z);

	if (decorations.empty() || decorations.back()->getBounds().right() < cameraBounds.right()) {
		generateDecoration(cameraBounds);
	}
	
	if (!decorations.empty() && decorations.front()->getBounds().right() < cameraBounds.left()) {
		scene->removeObject(decorations.front());
		decorations.erase(decorations.begin());
	}
}
	
void Background::generateDecoration(const math::RectFloat &cameraBounds) {
	float x = cameraBounds.right() + randomFloat(1.0f, 3.0f);
	float y = cameraBounds.bottom();
	float width = randomFloat(4.0f, 12.0f);
	float height = randomFloat(2.0f, maxHeight);
	
	auto rectangle = std::shared_ptr <shape::Rectangle> (new shape::Rectangle(scene->getHardware(), { x, y, width, height }));
	rectangle->setZPosition(z);
	rectangle->setColor(color);
	
	decorations.push_back(rectangle);
	scene->addObject(rectangle);
}

}}
