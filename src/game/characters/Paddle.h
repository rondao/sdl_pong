/*
 * Paddle.h
 *
 *  Created on: 05/03/2014
 *      Author: Rafael Rondao
 */

#pragma once

#include <gl/glew.h>

#include "../../libs/glm/glm.hpp"
#include "../../core/loaders/Data2D.h"

class Paddle
{
public:
	Paddle();
	virtual ~Paddle();

private:
	GLuint vao;
	GLuint ebo;
	GLuint bVertices;
	GLuint bColors;

public:
	GLuint sizePosition, sizeColor, sizeEbo;
	GLfloat* dataPosition;
	GLfloat* dataColor;
	GLuint* dataEbo;

	glm::mat4 modelMatrix;

public:
	void onInit();
	void onRender();

	void transformModelMatrix(const glm::mat4 &modelMatrix);
	const glm::mat4& getModelMatrix();

	void setPositionAttrib(GLuint posAttrib);
	void setColorAttrib(GLuint colAttrib);
};