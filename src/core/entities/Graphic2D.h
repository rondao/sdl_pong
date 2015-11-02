/*
* Core.h
*
*  Created on: 02/11/2015
*      Author: rafael.rondao
*/

#pragma once

#include <gl/glew.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "../exceptions/Fatalerror.h"

#include "../../libs/glm/glm.hpp"

class Graphic2D
{
public:
	Graphic2D(const char* filename);
	virtual ~Graphic2D();

private:
	GLuint vao;
	GLuint ebo;
	GLuint bVertices;
	GLuint bColors;

	GLuint sizePosition, sizeColor, sizeEbo;
	GLfloat* dataPosition;
	GLfloat* dataColor;
	GLuint* dataEbo;

	glm::mat4 modelMatrix;

public:
	void onRender();

	void transformModelMatrix(const glm::mat4 &modelMatrix);
	const glm::mat4& getModelMatrix();

	void setPositionAttrib(GLuint posAttrib);
	void setColorAttrib(GLuint colAttrib);

	void loadFromFile(const char* filename);
};