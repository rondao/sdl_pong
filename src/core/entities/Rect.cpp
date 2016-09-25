/*
* Rect.cpp
*
*  Created on: 14/11/2015
*      Author: rafael.rondao
*/

#include "Rect.h"

Rect::Rect() {
}

Rect::Rect(float x, float y, float w, float h) {
	this->origin = glm::vec2(x, y);
	this->width = w;
	this->height = h;
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

bool Rect::isColliding(const Rect& other) {
	const float *thisOrigin = (const float*) glm::value_ptr(this->origin);
	const float *otherOrigin = (const float*) glm::value_ptr(other.origin);

	return (thisOrigin[0] < otherOrigin[0] + other.width
		&& thisOrigin[0] + this->width > otherOrigin[0]
		&& thisOrigin[1] < otherOrigin[1] + other.height
		&& this->height + thisOrigin[1] > otherOrigin[1]);
}

bool Rect::isInside(const Rect& other) {
	const float *thisOrigin = (const float*)glm::value_ptr(this->origin);
	const float *otherOrigin = (const float*)glm::value_ptr(other.origin);

	return (thisOrigin[0] > otherOrigin[0]
		&& thisOrigin[0] + this->width < otherOrigin[0] + other.width
		&& thisOrigin[1] > otherOrigin[1]
		&& this->height + thisOrigin[1] < otherOrigin[1] + other.height);
}

// Load from a file with cursor already positioned with Rect information.
void Rect::loadFromFile(std::ifstream& file) {
	float x, y;
	file >> x >> y >> this->width >> this->height;
	this->origin = glm::vec2(x, y);
}

glm::vec2 Rect::getOrigin() {
	return this->origin;
}

float Rect::getWidth() {
	return this->width;
}

float Rect::getHeight() {
	return this->height;
}