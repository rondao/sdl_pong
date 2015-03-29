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
}