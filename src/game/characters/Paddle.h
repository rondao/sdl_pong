/*
 * Paddle.h
 *
 *  Created on: 05/03/2014
 *      Author: Rafael Rondao
 */

#pragma once

#include <gl/glew.h>

#include "../../libs/glm/glm.hpp"

// TODO: Remove hardcoded graphics information.

// Vertices positions (x, y).
const float POSITIONS[] = {
	-0.15f, 1.0f, // Top-left.
	0.15f, 1.0f, // Top-right.
	0.15f, -1.0f, // Bottom-right.
	-0.15f, -1.0f  // Bottom-left.
	};

// Vertices colors (r, g, b).
const float COLORS[] = {
	1.0f, 1.0f, 1.0f, // Top-left.
	1.0f, 1.0f, 1.0f, // Top-right.
	1.0f, 1.0f, 1.0f, // Bottom-right.
	1.0f, 1.0f, 1.0f  // Bottom-left.
	};

// Vertices indices.
const GLuint EBO[] = {
	0, 1, 2, // Top-right triangle.
	2, 3, 0  // Bottom-left triangle.
	};

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

	glm::mat4 modelMatrix;

public:
	void onInit();
	void onRender();

	void transformModelMatrix(const glm::mat4 &modelMatrix);
	const glm::mat4& getModelMatrix();

	void setPositionAttrib(GLuint posAttrib);
	void setColorAttrib(GLuint colAttrib);
};