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