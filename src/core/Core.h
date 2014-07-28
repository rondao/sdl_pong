/*
 * Core.h
 *
 *  Created on: 30/08/2010
 *      Author: rondao
 */

#pragma once

#include <sstream>

#include <gl\glew.h>
#include <SDL2\SDL.h>

#include "interfaces/IScene.h"
#include "exceptions\FatalError.h"

// Core of the game.
class Core {
private:
	// Controls if the game is running.
	bool running;

	// SDL buffers.
	SDL_Window* sdlMainWindow;
	SDL_GLContext sdlGlContext;

	// Current Scene.
	IScene* scene;

	// Windows size.
	int width;
	int height;

public:
	Core();
	virtual ~Core();

	void execute();
	virtual void init();
	void handleEvent(SDL_Event *event);
	void onExit();

	void setWidth(int width) {
		this->width = width;
	}
	int getWidth() {
		return width;
	}

	void setHeight(int height) {
		this->height = height;
	}
	int getHeight() {
		return height;
	}

	// Should be overwritten to return game's main scene.
	virtual IScene* getMainScene() = 0;
};

