#include "BBRenderer.h"

void BBRenderer::renderRect(Rect rect, const glm::mat4 &transformMatrix) {
	const float *origin = (const float*)glm::value_ptr(rect.getOrigin());

	this->dataPosition = std::make_shared<std::vector<GLfloat>>(std::vector<GLfloat>(8));
	this->dataPosition->data()[0] = origin[0];
	this->dataPosition->data()[1] = origin[1];
	this->dataPosition->data()[2] = origin[0] + rect.getWidth();
	this->dataPosition->data()[3] = origin[1];
	this->dataPosition->data()[4] = origin[0] + rect.getWidth();
	this->dataPosition->data()[5] = origin[1] + rect.getHeight();
	this->dataPosition->data()[6] = origin[0];
	this->dataPosition->data()[7] = origin[1] + rect.getHeight();

	this->dataColor = std::make_shared<std::vector<GLfloat>>(std::vector<GLfloat>(12));
	for (std::vector<GLfloat>::iterator it = dataColor->begin(); it != dataColor->end(); ++it) {
		*it = 0.5f;
	}

	this->dataEbo = std::make_shared<std::vector<GLuint>>(std::vector<GLuint>(6));
	this->dataEbo->data()[0] = 0;
	this->dataEbo->data()[1] = 1;
	this->dataEbo->data()[2] = 2;
	this->dataEbo->data()[3] = 2;
	this->dataEbo->data()[4] = 3;
	this->dataEbo->data()[5] = 0;

	this->boundingBox = rect;

	this->onInit();

	this->setPositionAttrib(Shader::getCurrentShader()->getAttrib("position"));
	this->setColorAttrib(Shader::getCurrentShader()->getAttrib("color"));

	GLuint uniTrans = Shader::getCurrentShader()->getUniform("model");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(transformMatrix));
	this->onRender();
}