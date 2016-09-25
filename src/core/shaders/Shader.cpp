/*
 * Shaders.cpp
 *
 *  Created on: 18/08/2013
 *      Author: Rafael Rondao
 */

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include <GL/glew.h>

#include "Shader.h"

Shader::Shader() {
	vertexShader = 0;
	fragmentShader = 0;
	shaderProgram = 0;
}

Shader::Shader(const char* vertFilename, const char* fragFilename) {
	vertexShader = loadFromFile(vertFilename, GL_VERTEX_SHADER);
	fragmentShader = loadFromFile(fragFilename, GL_FRAGMENT_SHADER);

	linkProgram();
}

Shader::~Shader() {

}

Shader* Shader::currentShader = NULL;
Shader* Shader::getCurrentShader() {
	return Shader::currentShader;
}

void Shader::linkProgram() {
	// Link the vertex and fragment shader into a shader program.
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	// Set the variable that contains the output of the Fragment Shader.
	// A Fragment Shader may have more than one output.
	// Binding the output data of the Fragment Shader should be done before linking.
	// TODO: Hardcoded output data variable.
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);

	GLint success = 0;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (success != GL_TRUE) {
		GLint maxLength = 0;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		char* errorLog = new char[maxLength];
		glGetProgramInfoLog(shaderProgram, maxLength, &maxLength, errorLog);

		std::stringstream ss;
		ss << "Failed to link shader Program: " << std::endl << errorLog << std::endl;
		throw FatalError(ss.str());
	}

	// After linking the Shaders, they can be deleted.
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::useProgram() {
	glUseProgram(shaderProgram);
	Shader::currentShader = this;
}

GLuint Shader::loadFromFile(const char* filename, GLuint shaderType) {
	std::ifstream file;

	file.open(filename);

	if (!file.good()) {
		std::stringstream ss;
		ss << "Failed to load Shader: " << filename << std::endl;
		throw FatalError(ss.str());
	}

	// Create a string stream
	std::stringstream stream;

	// Dump the contents of the file into it
	stream << file.rdbuf();

	// Close the file
	file.close();

	// Get the source string as a pointer to an array of characters
	std::string filestring = stream.str();
	const char *shaderSource = filestring.c_str();

	// Associate the source with the shader id
	GLuint newShader = glCreateShader(shaderType);
	glShaderSource(newShader, 1, &shaderSource, NULL);
	glCompileShader(newShader);

	GLint success = 0;
	glGetShaderiv(newShader, GL_COMPILE_STATUS, &success);

	if (success != GL_TRUE) {
		GLint maxLength = 0;
		glGetShaderiv(newShader, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		char* errorLog = new char[maxLength];
		glGetShaderInfoLog(newShader, maxLength, &maxLength, errorLog);

		std::stringstream ss;
		ss << "Failed to load Compile Shader: " << filename << std::endl
				<< errorLog << std::endl;
		throw FatalError(ss.str());
	}

	return newShader;
}

GLuint Shader::getAttrib(const char* attrib) {
	return glGetAttribLocation(shaderProgram, attrib);
}

GLuint Shader::getUniform(const char * uniform) {
	return glGetUniformLocation(shaderProgram, uniform);
}
