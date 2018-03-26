//
//  Number.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 08.01.17.
//  Copyright © 2017 Yuriy Chudin. All rights reserved.
//

#include "Number.h"
#include <tuple>
#include "graphics/hardware/VertexBuffer.h"
#include "graphics/hardware/Hardware.h"

using namespace graphics;

namespace game {
namespace node {
	
Number::Number(hardware::Hardware *hardware, unsigned int value)
	: graphics::node::shape::Shape(hardware)
	, value(value)
{
	vertexBuffer.reset(hardware->createVertexBuffer(0, 0));
	
	rebuild();
}
	
Number::~Number() {}
	
void Number::setValue(const unsigned int &val) {
	value = val;
	rebuild();
}
	
static void addElement(std::vector<Vertex> &vertices, std::vector <unsigned short> &indices, const math::Vec2f &pos, int type) {
	/*  1----------2
	   /            \
	  /              \
	 0                3
	  \              /
	   \            /
	    5----------4
	 
	
	 types:
	 
           0
	      ---
		1|   |2
		  -3-
		4|   |5
	      ---
	       6
	 */
	
	static math::Vec2f v[6] = {
		{ 0.1f, 0.0f },
		{ 0.2f, 0.1f },
		{ 0.8f, 0.1f },
		{ 0.9f, 0.0f },
		{ 0.8f, -0.1f },
		{ 0.2f, -0.1f },
	};
	
	static unsigned short ind[12] = {
		0, 1, 5,
		5, 1, 2,
		5, 2, 4,
		2, 3, 4
	};

	static std::pair <math::Vec2f, bool> e[7] = {
		{ math::Vec2f(-0.5f, 1.0f), false },
		{ math::Vec2f(-0.5f, 1.0f), true },
		{ math::Vec2f(0.5f, 1.0f), true },
		{ math::Vec2f(-0.5f, 0.0f), false },
		{ math::Vec2f(-0.5f, 0.0f), true },
		{ math::Vec2f(0.5f, 0.0f), true },
		{ math::Vec2f(-0.5f, -1.0f), false }
	};
	
	size_t indexOffset = vertices.size();

	bool vertical = e[type].second;
	math::Vec2f p = pos + e[type].first;
	
	for (int i = 0; i < 6; i++)
		vertices.push_back( { p + (vertical ? math::Vec2f(v[i].y, -v[i].x) : v[i]), 0 } );
	
	for (int i = 0; i < 12; i++)
		indices.push_back(ind[i] + indexOffset);
}
	
void Number::rebuild() {
	std::vector <Vertex> vertices;
	std::vector <hardware::VertexBuffer::Index> indices;
	
	static std::vector <unsigned char> digitMap[10] = {
		/* 0 */ { 0, 1, 2, 4, 5, 6 },
		/* 1 */ { 2, 5 },
		/* 2 */ { 0, 2, 3, 4, 6 },
		/* 3 */ { 0, 2, 3, 5, 6 },
		/* 4 */ { 1, 2, 3, 5 },
		/* 5 */ { 0, 1, 3, 5, 6 },
		/* 6 */ { 0, 1, 3, 4, 5, 6 },
		/* 7 */ { 0, 2, 5 },
		/* 8 */ { 0, 1, 2, 3, 4, 5, 6 },
		/* 9 */ { 0, 1, 2, 3, 5, 6 },
	};
	
	std::vector <unsigned char> digits;
	int value = this->value;
	while (value > 0) {
		digits.insert(digits.begin(), value % 10);
		value /= 10;
	}
	
	if (digits.size() == 0) {
		digits.push_back(0);
	}

	const float offset = 1.5f;
	const float startPos = (digits.size() - 1) * offset / 2.0f;
	for (size_t i = 0; i < digits.size(); i++) {
		for (auto type: digitMap[digits[i]]) {
			addElement(vertices, indices, { -startPos + offset * i, 0.0f }, type);
		}
	}
	
	vertexBuffer->fillVertices(vertices);
	vertexBuffer->fillIndices(indices);
}
	
}}
