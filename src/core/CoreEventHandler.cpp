/*
 * CoreEventHandler.cpp
 *
 *  Created on: 04/08/2013
 *      Author: Rafael Rondao
 */

#include "Core.h"

// onExit event.
void Core::onExit() {
	running = false;
}

// Check which type the event is, calling the associated function.
// Redirect event handling to current Scene. Only handles 'SDL_Quit' event.
void Core::handleEvent(SDL_Event* event) {
	switch (event->type) {
	case SDL_KEYDOWN: {
		scene->onKeyDown(event->key.keysym.sym, event->key.keysym.mod);
		break;
	}

	case SDL_KEYUP: {
		break;
	}

	case SDL_MOUSEMOTION: {
		break;
	}

		case SDL_MOUSEBUTTONDOWN: {
			switch (event->button.button) {
				case SDL_BUTTON_LEFT: {
					break;
				}
				case SDL_BUTTON_RIGHT: {
					break;
				}
				case SDL_BUTTON_MIDDLE: {
					break;
				}
			}
			break;
		}

		case SDL_MOUSEBUTTONUP: {
			switch (event->button.button) {
				case SDL_BUTTON_LEFT: {
					break;
				}
				case SDL_BUTTON_RIGHT: {
					break;
				}
				case SDL_BUTTON_MIDDLE: {
					break;
				}
			}
			break;
		}

		case SDL_JOYAXISMOTION: {
			break;
		}

		case SDL_JOYBALLMOTION: {
			break;
		}

		case SDL_JOYHATMOTION: {
			break;
		}
		case SDL_JOYBUTTONDOWN: {
			break;
		}

		case SDL_JOYBUTTONUP: {
			break;
		}

		case SDL_QUIT: {
			onExit();
			break;
		}

		case SDL_SYSWMEVENT: {
			break;
		}

		default: {
			break;
		}
	}
}
