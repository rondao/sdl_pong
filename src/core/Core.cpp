/*
* Core.cpp
*
*  Created on: 30/08/2010
*      Author: rondao
*/

#include "Core.h"

// Make the game core, initiating the windows status.
Core::Core() {
	running = true;

	// TODO: Fixed values for Size.
	width = 640;
	height = 480;
}

Core::~Core() {
}

// Start the core. Execute the main loop.
int Core::execute() {
	if (!init()) {
		return 0;
	}

	SDL_Event event;

	while (running) {
		while (SDL_PollEvent(&event)) {
			handleEvent(&event);
		}

		SDL_GL_SwapWindow(sdlMainWindow);
	}

	SDL_GL_DeleteContext(sdlGlContext);
	SDL_Quit();

	return 1;
}

// Initialize the SDL sub-systems.
int Core::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return 0;
	}

	sdlMainWindow = SDL_CreateWindow("p01_pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, getWidth(), getHeight(), SDL_WINDOW_OPENGL);
	sdlGlContext = SDL_GL_CreateContext(sdlMainWindow);

	return 1;
}
