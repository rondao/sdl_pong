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
	virtual ~IScene() {};

public:
	virtual void onInit() {};
	virtual void onPreUpdate() {};
	virtual void onUpdate() {};
	virtual void onRender(float fpsInterpolation) {};
};
