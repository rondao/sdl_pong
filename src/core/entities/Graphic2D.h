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

#include "../../libs/glm/glm.hpp"

#include "../exceptions/Fatalerror.h"
#include "Rect.h"

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
	glm::mat4 prevModelMatrix;

protected:
	Rect boundingBox;

	std::shared_ptr<std::vector<GLfloat>> dataPosition;
	std::shared_ptr<std::vector<GLfloat>> dataColor;
	std::shared_ptr<std::vector<GLuint>> dataEbo;

public:
	void onInit();
	void onPreUpdate();
	void onRender();

	void transformModelMatrix(const glm::mat4 &transformMatrix);
	void resetModelMatrix();
	const glm::mat4 getModelMatrix(float fpsInterpolation);

	void setPositionAttrib(GLuint posAttrib);
	void setColorAttrib(GLuint colAttrib);

	bool isColliding(const Graphic2D& other);
	bool isColliding(const Rect& rect);

	void loadFromFile(const char* filename);

	Rect getBoundingBox();
};