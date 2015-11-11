/*
* FPS.h
*
*  Created on: 10/11/2015
*      Author: rafael.rondao
*/

#include "GameTime.h"

GameTime::GameTime(unsigned int ups) : UPDATE_TIME(1000 / ups) {
	this->ups = ups;
}

GameTime::~GameTime() {
}

bool GameTime::hasUpdateTimePassed() {
	if (SDL_GetTicks() > this->timeNextUpdate) {
		advanceNextUpdateTime();
		return true;
	}
	else {
		return false;
	}
}

void GameTime::advanceNextUpdateTime() {
	this->timeNextUpdate += this->UPDATE_TIME;
}

void GameTime::reset() {
	this->timeNextUpdate = SDL_GetTicks();
}