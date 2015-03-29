/*
 * Shaders.h
 *
 *  Created on: 18/08/2013
 *      Author: Rafael Rondao
 */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <gl/glew.h>

#include "../exceptions/FatalError.h"

class Shader {
public:
	Shader();
	Shader(const char* vertFilename, const char* fragFilename);
	virtual ~Shader();

private:
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;

public:
	GLuint loadFromFile(const char* filename, GLuint shaderType);

	void linkProgram();
	void useProgram();

	GLuint getAttrib(const char * attrib);
};
