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

	Paddle leftPaddle;
	Paddle rightPaddle;

public:
	void onInit();
	void onUpdate();
	void onRender();

	void onKeyDown(SDL_Keycode sym, Uint16 mod);
};
