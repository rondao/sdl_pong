/*
 * Game.h
 *
 *  Created on: 04/08/2013
 *      Author: Rafael Rondao
 */

#pragma once

#include "../core/Core.h"
#include "../core/interfaces/IScene.h"
#include "scene/StartScn.h"

class Game: public Core {
public:
	Game();
	virtual ~Game();

private:
	int width;
	int height;

public:
	IScene* getMainScene();
};
