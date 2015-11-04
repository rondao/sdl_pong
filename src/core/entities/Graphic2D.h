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
#include <memory>
#include <vector>

#include "../exceptions/Fatalerror.h"

#include "../../libs/glm/glm.hpp"

class Graphic2D
{
public:
	Graphic2D();
	virtual ~Graphic2D();

private:
	GLuint vao;
	GLuint ebo;
	GLuint bVertices;
	GLuint bColors;

	glm::mat4 modelMatrix;

protected:
	std::shared_ptr<std::vector<GLfloat>> dataPosition;
	std::shared_ptr<std::vector<GLfloat>> dataColor;
	std::shared_ptr<std::vector<GLuint>> dataEbo;

public:
	void onInit();
	void onRender();

	void transformModelMatrix(const glm::mat4 &modelMatrix);
	const glm::mat4& getModelMatrix();

	void setPositionAttrib(GLuint posAttrib);
	void setColorAttrib(GLuint colAttrib);

	void loadFromFile(const char* filename);
};