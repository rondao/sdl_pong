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

	width = 0;
	height = 0;

	scene = NULL;
}

Core::~Core() {
}

// Start the core. Execute the main loop.
void Core::execute() {
	init();

	scene = getMainScene();
	scene->onInit();

	SDL_Event event;

	while (running) {
		while (SDL_PollEvent(&event)) {
			handleEvent(&event);
		}

		scene->onUpdate();
		scene->onRender();

		SDL_GL_SwapWindow(sdlMainWindow);
	}

	delete scene;

	SDL_GL_DeleteContext(sdlGlContext);
	SDL_Quit();
}

// Initialize the SDL sub-systems.
void Core::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::stringstream ss;
		ss << "Failed to initialize SDL Systems" << std::endl
				<< "SDL Error: " << SDL_GetError() << std::endl;
		throw FatalError(ss.str());
	}

	sdlMainWindow = SDL_CreateWindow("p01_pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, getWidth(), getHeight(), SDL_WINDOW_OPENGL);
	sdlGlContext = SDL_GL_CreateContext(sdlMainWindow);

	//	glewExperimental = TRUE; // Needed for newest extensions.
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		std::stringstream ss;
		ss << "Failed to initialize GLEW Systems" << std::endl
				<< "GLEW Error: " << err << std::endl;
		throw FatalError(ss.str());
	}
}
