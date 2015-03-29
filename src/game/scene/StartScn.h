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

class StartScn : public IScene {
public:
	StartScn();
	virtual ~StartScn();

private:
	Shader defaultShader;
	Paddle leftPaddle;

public:
	void onInit();
	void onRender();
};
