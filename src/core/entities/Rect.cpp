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

Rect Rect::applyModelMatrix(const glm::mat4 &transformMatrix) {
	Rect newBB;

	const float *bbOrigin = (const float*)glm::value_ptr(this->origin);
	const float *bbOriginAfter = (const float*)glm::value_ptr(glm::vec2(transformMatrix * glm::vec4(this->origin, 0.0f, 1.0f)));
	const float *bbEndAfter = glm::value_ptr(glm::vec2(transformMatrix * glm::vec4(bbOrigin[0] + this->width, bbOrigin[1] + this->height, 0.0f, 1.0f)));

	newBB.origin = glm::vec2(bbOriginAfter[0], bbOriginAfter[1]);
	newBB.width = abs(bbOriginAfter[0] - bbEndAfter[0]);
	newBB.height = abs(bbOriginAfter[1] - bbEndAfter[1]);

	return newBB;
}

bool Rect::checkCollision(const Rect& other) {
	const float *thisOrigin = (const float*) glm::value_ptr(this->origin);
	const float *otherOrigin = (const float*) glm::value_ptr(other.origin);

	return (abs(thisOrigin[0] - otherOrigin[0]) * 2 < this->width + other.width)
		&& (abs(thisOrigin[1] - otherOrigin[1]) * 2 < this->height + other.height);
}

// Load from a file with cursor already positioned with Rect information.
void Rect::loadFromFile(std::ifstream& file) {
	float x, y;
	file >> x >> y >> this->width >> this->height;
	this->origin = glm::vec2(x, y);
}