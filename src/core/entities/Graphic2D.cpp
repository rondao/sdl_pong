/*
* Core.h
*
*  Created on: 02/11/2015
*      Author: rafael.rondao
*/

#include "Graphic2D.h"

Graphic2D::Graphic2D() {
}

Graphic2D::~Graphic2D() {
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &bVertices);
	glDeleteBuffers(1, &bColors);
}

void Graphic2D::onInit() {
	// Create Vertex Array Object.
	// This contains the Metadata on how the data of the VBO is stored.
	// When 'glVertexAttribPointer' is called, the information is stored on the current VAO.
	// Also store the EBO binded.
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Create a Vertex Buffer Object and copy the vertex data to it.
	glGenBuffers(1, &bVertices);

	// Make this vbo the active ARRAY_BUFFER.
	glBindBuffer(GL_ARRAY_BUFFER, bVertices);
	// [1] Which current type of buffer to copy; [2] Number of bytes to copy; [3] Data to copy from;
	// - GL_STATIC_DRAW: The vertex data will be uploaded once and drawn many times (e.g. the world).
	// - GL_DYNAMIC_DRAW: The vertex data will be changed from time to time, but drawn many times more than that.
	// - GL_STREAM_DRAW: The vertex data will change almost every time it's drawn (e.g. user interface).
	glBufferData(GL_ARRAY_BUFFER, dataPosition->size() * sizeof(GLfloat), dataPosition->data(), GL_STATIC_DRAW);

	// Create a Color Buffer Object and copy the color data to it.
	glGenBuffers(1, &bColors);

	// Make this cbo the active ARRAY_BUFFER.
	glBindBuffer(GL_ARRAY_BUFFER, bColors);
	// [1] Which current type of buffer to copy; [2] Number of bytes to copy; [3] Data to copy from;
	// - GL_STATIC_DRAW: The vertex data will be uploaded once and drawn many times (e.g. the world).
	// - GL_DYNAMIC_DRAW: The vertex data will be changed from time to time, but drawn many times more than that.
	// - GL_STREAM_DRAW: The vertex data will change almost every time it's drawn (e.g. user interface).
	glBufferData(GL_ARRAY_BUFFER, dataColor->size() * sizeof(GLfloat), dataColor->data(), GL_STATIC_DRAW);

	// Create an element array.
	// This contains the Indices of the Vertices to assembly the triangles.
	glGenBuffers(1, &ebo);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataEbo->size() * sizeof(GLuint), dataEbo->data(), GL_STATIC_DRAW);

	// Releasing VAO to protect it from external changes.
	glBindVertexArray(0);
}

void Graphic2D::onPreUpdate() {
	this->prevModelMatrix = this->modelMatrix;
}

void Graphic2D::onRender() {
	// Draw the current VBO data, using VAO and EBO metadata.
	// [1] Primitive to draw; [2] Number of vertices;
	//  [3] Data of VAO and EBO (they are indices); [4] Offset
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

// The closest fpsInterpolation is to 0, the closest it is to the nextUpdateFrame.
// Which means it's getting close to the final modelMatrix value.
const glm::mat4 Graphic2D::getModelMatrix(float fpsInterpolation) {
	return this->modelMatrix + fpsInterpolation * (this->prevModelMatrix - this->modelMatrix);
}

void Graphic2D::transformModelMatrix(const glm::mat4 &transformMatrix) {
	this->modelMatrix = transformMatrix * this->modelMatrix;
}

void Graphic2D::setPositionAttrib(GLuint posAttrib) {
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, bVertices);
	glEnableVertexAttribArray(posAttrib);
	// [1] The attrib to set; [2] Size (number of components) of the input (x,y); [3] Input values type;
	//  [4] If input values should be normalized (-1.0, 1.0) or (0.0, 1.0); [5] Stride; [6] array offset.
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glBindVertexArray(0);
}

void Graphic2D::setColorAttrib(GLuint colAttrib) {
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, bColors);
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindVertexArray(0);
}

void Graphic2D::loadFromFile(const char* filename) {
	std::ifstream file;

	file.open(filename);
	if (!file.good()) {
		std::stringstream ss;
		ss << "Failed to load 2D data: " << filename << std::endl;
		throw FatalError(ss.str());
	}

	int bufferSize;
	// Reading 2D position vertices
	file >> bufferSize;
	this->dataPosition = std::make_shared<std::vector<GLfloat>>(std::vector<GLfloat>(bufferSize));
	for (std::vector<GLfloat>::iterator it = dataPosition->begin(); it != dataPosition->end(); ++it) {
		file >> *it;
	}

	// Reading RGB colors
	file >> bufferSize;
	this->dataColor = std::make_shared<std::vector<GLfloat>>(std::vector<GLfloat>(bufferSize));
	for (std::vector<GLfloat>::iterator it = dataColor->begin(); it != dataColor->end(); ++it) {
		file >> *it;
	}

	// Reading triangles EBOs
	file >> bufferSize;
	this->dataEbo = std::make_shared<std::vector<GLuint>>(std::vector<GLuint>(bufferSize));
	for (std::vector<GLuint>::iterator it = dataEbo->begin(); it != dataEbo->end(); ++it) {
		file >> *it;
	}

	// Close the file
	file.close();
}