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

	// Specify the layout of the vertex data. This information is stored on active VAO.
	// Inform how the 'position' variable from the Vertex Shader must be acquired from the VBO.
	leftPaddle.setPositionAttrib(defaultShader.getAttrib("position"));

	// Inform how the 'color' variable from the Vertex Shader must be acquired from the VBO.
	leftPaddle.setColorAttrib(defaultShader.getAttrib("color"));
}

void StartScn::onRender() {
	// Clear the screen to black.
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	leftPaddle.onRender();
}