//
//  Random.cpp
//  FlappyBird
//
//  Created by Yuriy Chudin on 09.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#include "Random.h"
#include <cstdlib>
#include <ctime>

void randomSeed() {
	srand((unsigned) (time(0)));
}

float randomFloat(float min, float max) {
	float r = (float) (rand()) / (float) (RAND_MAX);
	return r * (max - min) + min;
}
