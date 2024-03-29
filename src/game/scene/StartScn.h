/*
 * StartScn.h
 *
 *  Created on: 04/08/2013
 *      Author: Rafael Rondao
 */

#pragma once

#include "../../core/interfaces/IScene.h"

#include "../../core/shaders/Shader.h"
#include "../characters/Paddle.h"

#include "../../libs/glm/glm.hpp"
#include "../../libs/glm/gtx/transform.hpp"
#include "../../libs/glm/gtc/type_ptr.hpp"

class StartScn : public IScene {
public:
	StartScn();
	virtual ~StartScn();

private:
	Shader defaultShader;

	Rect playArea;

	Paddle leftPaddle;
	Paddle rightPaddle;

public:
	void onInit();
	void onPreUpdate();
	void onUpdate();
	void onRender(float fpsInterpolation);

	void onKeyDown(SDL_Keycode sym, Uint16 mod);
	void onKeyUp(SDL_Keycode sym, Uint16 mod);
};
