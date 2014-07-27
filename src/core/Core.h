/*
 * Core.h
 *
 *  Created on: 30/08/2010
 *      Author: rondao
 */

#pragma once

#include <gl\glew.h>
#include <SDL2\SDL.h>

// Core of the game.
class Core {
private:
	// Controls if the game is running.
	bool running;

	// SDL buffers.
	SDL_Window* sdlMainWindow;
	SDL_GLContext sdlGlContext;

	// Windows size.
	int width;
	int height;

public:
	Core();
	virtual ~Core();

	int execute();
	virtual int init();
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
};

