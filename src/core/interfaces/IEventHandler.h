/*
 * IEventHandler.h
 *
 *  Created on: 04/08/2013
 *      Author: Rafael Rondao
 */

#pragma once

#include <SDL2/SDL_keycode.h>

// Interface for handling all SDL possible events.
class IEventHandler {
public:
	IEventHandler() {};
	virtual ~IEventHandler() = 0 {};

public:
	// =======================
	// All SDL possible events.
	virtual void onInputFocus() {};
	virtual void onInputBlur() {};
	virtual void onKeyDown(SDL_Keycode sym, Uint16 mod) {};
	virtual void onKeyUp(SDL_Keycode sym, Uint16 mod) {};
	virtual void onMouseFocus() {};
	virtual void onMouseBlur() {};
	virtual void onMouseMove(int mX, int mY, int relX, int relY, bool Left,
			bool Right, bool Middle) {};
	virtual void onMouseWheel(bool Up, bool Down) {};
	virtual void onLButtonDown(int mX, int mY) {};
	virtual void onLButtonUp(int mX, int mY) {};
	virtual void onRButtonDown(int mX, int mY) {};
	virtual void onRButtonUp(int mX, int mY) {};
	virtual void onMButtonDown(int mX, int mY) {};
	virtual void onMButtonUp(int mX, int mY) {};
	virtual void onJoyAxis(Uint8 which, Uint8 axis, Sint16 value) {};
	virtual void onJoyButtonDown(Uint8 which, Uint8 button) {};
	virtual void onJoyButtonUp(Uint8 which, Uint8 button) {};
	virtual void onJoyHat(Uint8 which, Uint8 hat, Uint8 value) {};
	virtual void onJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel) {};
	virtual void onMinimize() {};
	virtual void onRestore() {};
	virtual void onResize(int w, int h) {};
	virtual void onExpose() {};
	// virtual void onExit() {}; // This method is not for Scenes, exclusive for Core.
	virtual void onUser(Uint8 type, int code, void* data1, void* data2) {};
};

