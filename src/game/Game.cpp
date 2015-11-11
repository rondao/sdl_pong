/*
 * Game.cpp
 *
 *  Created on: 04/08/2013
 *      Author: Rafael Rondao
 */

#include "Game.h"

// TODO: Hardcoded UPS.
Game::Game() : Core(30) {
	// TODO: Hardcoded window size.
	setWidth(640);
	setHeight(480);
}

Game::~Game() {
}

IScene* Game::getMainScene() {
	return new StartScn();
}