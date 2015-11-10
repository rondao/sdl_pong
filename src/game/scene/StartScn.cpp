/*
 * StartScn.cpp
 *
 *  Created on: 04/08/2013
 *      Author: Rafael Rondao
 */

#include "StartScn.h"

StartScn::StartScn() :
	// TODO: Hardcoded shader loading.
	defaultShader("res/shaders/defaultShader.vert", "res/shaders/defaultShader.frag") {
}

StartScn::~StartScn() {
}

void StartScn::onInit() {
	defaultShader.useProgram();
	leftPaddle.onInit();
	rightPaddle.onInit();

	// TODO: hardcoded scalation.
	leftPaddle.transformModelMatrix(glm::scale(glm::vec3(0.15, 0.15, 1.0)));
	leftPaddle.transformModelMatrix(glm::translate(glm::vec3(-0.9, 0.0, 0.0)));
	// TODO: hardcoded scalation.
	rightPaddle.transformModelMatrix(glm::scale(glm::vec3(0.15, 0.15, 1.0)));
	rightPaddle.transformModelMatrix(glm::translate(glm::vec3(0.9, 0.0, 0.0)));

	// Specify the layout of the vertex data. This information is stored on active VAO.
	// Inform how the 'position' variable from the Vertex Shader must be acquired from the VBO.
	leftPaddle.setPositionAttrib(defaultShader.getAttrib("position"));
	rightPaddle.setPositionAttrib(defaultShader.getAttrib("position"));

	// Inform how the 'color' variable from the Vertex Shader must be acquired from the VBO.
	leftPaddle.setColorAttrib(defaultShader.getAttrib("color"));
	rightPaddle.setColorAttrib(defaultShader.getAttrib("color"));
}

void StartScn::onRender() {
	// Clear the screen to black.
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLuint uniTrans = defaultShader.getUniform("model");

	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(leftPaddle.getModelMatrix()));
	leftPaddle.onRender();

	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(rightPaddle.getModelMatrix()));
	rightPaddle.onRender();
}

void StartScn::onUpdate() {
	leftPaddle.move();
}

// TODO: Remove SDL Specifics. It should be on Core side.
void StartScn::onKeyDown(SDL_Keycode sym, Uint16 mod) {
	switch (sym) {
	case SDLK_UP:
		leftPaddle.setVelocity(0.0001f); // TODO: magic number. Need FPS System
		break;
	case SDLK_DOWN:
		leftPaddle.setVelocity(-0.0001f); // TODO: magic number.
		break;
	default:
		break;
	}
}