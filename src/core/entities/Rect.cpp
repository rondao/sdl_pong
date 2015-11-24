/*
* Rect.cpp
*
*  Created on: 14/11/2015
*      Author: rafael.rondao
*/

#include "Rect.h"

Rect::Rect() {
}

Rect::~Rect() {
}

bool Rect::checkCollision(const Rect& other) {
	const float *thisOrigin = (const float*) glm::value_ptr(this->origin);
	const float *otherOrigin = (const float*) glm::value_ptr(other.origin);

	return (abs(thisOrigin[0] - otherOrigin[0]) * 2 < this->width + other.width)
		&& (abs(thisOrigin[1] - otherOrigin[1]) * 2 < this->height + other.height);
}