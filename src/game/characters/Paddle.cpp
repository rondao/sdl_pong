/*
 * Paddle.cpp
 *
 *  Created on: 05/03/2014
 *      Author: Rafael Rondao
 */

#include "Paddle.h"

std::weak_ptr<std::vector<GLfloat>> Paddle::cachePosition;
std::weak_ptr<std::vector<GLfloat>> Paddle::cacheColor;
std::weak_ptr<std::vector<GLuint>> Paddle::cacheEbo;

Paddle::Paddle() {
	if (Paddle::cachePosition.expired() ||
		  Paddle::cacheColor.expired() ||
		  Paddle::cacheEbo.expired()) {
		loadFromFile("res/models/paddle.g2d");

		Paddle::cachePosition = this->dataPosition;
		Paddle::cacheColor = this->dataColor;
		Paddle::cacheEbo = this->dataEbo;
	} else {
		this->dataPosition = Paddle::cachePosition.lock();
		this->dataColor = Paddle::cacheColor.lock();
		this->dataEbo = Paddle::cacheEbo.lock();
	}
}

Paddle::~Paddle() {
}

void Paddle::move() {
	this->transformModelMatrix(glm::translate(glm::vec3(0.0, this->velocity, 0.0)));
}

void Paddle::setVelocity(float velocity) {
	this->velocity = velocity;
}