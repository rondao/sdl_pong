#include "Data2D.h"

void loadFromFile(const char* filename, Paddle* paddle) {
	std::ifstream file;

	file.open(filename);
	if (!file.good()) {
		std::stringstream ss;
		ss << "Failed to load 2D data: " << filename << std::endl;
		throw FatalError(ss.str());
	}

	// Reading 2D position vertices
	file >> paddle->sizePosition;
	paddle->dataPosition = new GLfloat[paddle->sizePosition];
	for (unsigned int i = 0; i < paddle->sizePosition; i++) {
		file >> paddle->dataPosition[i];
	}

	// Reading RGB colors
	file >> paddle->sizeColor;
	paddle->dataColor = new GLfloat[paddle->sizeColor];
	for (unsigned int i = 0; i < paddle->sizeColor; i++) {
		file >> paddle->dataColor[i];
	}

	// Reading triangles EBOs
	file >> paddle->sizeEbo;
	paddle->dataEbo = new GLuint[paddle->sizeEbo];
	for (unsigned int i = 0; i < paddle->sizeEbo; i++) {
		file >> paddle->dataEbo[i];
	}

	// Close the file
	file.close();
}