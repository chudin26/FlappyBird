//
//  Column.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 09.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "Column.h"
#include "Constants.h"
#include "Random.h"
#include "game/Application.h"
#include "graphics/node/shape/Rectangle.h"
#include "graphics/node/Scene.h"

namespace game {
namespace play {
	
Column::Column(graphics::node::Scene *scene, float pos)
	: scene(scene)
{
	const float columnHeight = 30.0f;
	const float y = randomFloat(0, COLUMN_Y_RANGE) - COLUMN_Y_RANGE / 2;
	const auto color = graphics::Color(0.1f, 0.8f, 0.1f);
	
	auto hardware = Application::getInstance()->getHardware();
	
	float offsetY[2] = { -columnHeight - COLUMN_HOLE_HEIGHT / 2, COLUMN_HOLE_HEIGHT / 2 };
	for (int i = 0; i < 2; i++) {
		auto rect = math::RectFloat(pos - COLUMN_WIDTH / 2, y + offsetY[i], getWidth(), columnHeight);
		rectangles[i].reset(new graphics::node::shape::Rectangle(hardware, rect));
		rectangles[i]->setZPosition(MAIN_Z_POSITION);
		rectangles[i]->setColor(color);
		
		scene->addObject(rectangles[i]);
	}
}

Column::~Column() {}
	
void Column::removeFromScene() {
	for (int i = 0; i < 2; i++)
		scene->removeObject(rectangles[i]);
}

float Column::getWidth() const {
	return COLUMN_WIDTH;
}
	
float Column::getRight() const {
	return rectangles[0]->getBounds().right();
}
	
std::vector <math::RectFloat> Column::getRects() const {
	return { rectangles[0]->getBounds(), rectangles[1]->getBounds() };
}
	
}}
