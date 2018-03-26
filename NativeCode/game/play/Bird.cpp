//
//  Bird.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 09.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "Bird.h"
#include "Column.h"
#include "Constants.h"
#include "Application.h"
#include "graphics/node/Scene.h"
#include "graphics/node/shape/Circle.h"
#include "math/Circle.h"

namespace game {
namespace play {
	
Bird::Bird(graphics::node::Scene *scene)
	: scene(scene)
	, pos({ 0, 4 })
	, velocityY(0.0f)
{
	auto hardware = Application::getInstance()->getHardware();
	circle.reset(new graphics::node::shape::Circle(hardware, getRadius()));
	circle->setColor(graphics::Color::white());
	circle->setZPosition(MAIN_Z_POSITION);
	
	scene->addObject(circle);
}

void Bird::lifecycle(float dt) {
	velocityY -= GRAVITY * dt;
	
	pos.x += BIRD_HORIZONTAL_VELOCITY * dt;
	pos.y += velocityY * dt;
	
	circle->setPosition(pos);
}

void Bird::jump() {
	velocityY = JUMP_IMPULSE;
}
	
void Bird::crash() {
	circle->setColor(graphics::Color::red());
}

float Bird::getRadius() const {
	return BIRD_RADIUS;
}
	
bool Bird::intersects(const math::RectFloat &bounds) {
	return pos.y + getRadius() > bounds.top() || pos.y - getRadius() < bounds.bottom();
}

bool Bird::intersects(const Column &column) {
	auto columnRects = column.getRects();
	auto circle = math::Circle(pos, getRadius());
	for (int i = 0; i < 2; i++)
		if (circle.intersect(columnRects[i]))
			return true;
	
	return false;
}
	
bool Bird::pass(const Column &column) {
	return pos.x - getRadius() > column.getRight();
}

}}
