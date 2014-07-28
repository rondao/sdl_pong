/*
 * IScene.h
 *
 *  Created on: 04/08/2013
 *      Author: Rafael Rondao
 */

#pragma once

#include "IEventHandler.h"
#include <SDL2/SDL_events.h>

// Interface for a scene.
class IScene : public IEventHandler {
public:
	IScene() {};
	virtual ~IScene() = 0 {};

public:
	virtual void onInit() {};
	virtual void onUpdate() {};
	virtual void onRender() {};
};
