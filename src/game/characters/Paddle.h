/*
 * Paddle.h
 *
 *  Created on: 05/03/2014
 *      Author: Rafael Rondao
 */

#pragma once

#include <memory>
#include <vector>

#include "../../core/entities/Graphic2D.h"

class Paddle : public Graphic2D
{
public:
	Paddle();
	virtual ~Paddle();

private:
	// TODO: This cache system access OpenGL data.
	//       All OpenGL stuff should be on Core side.
	//       Maybe create an interface from caching on Core side.
	static std::weak_ptr<std::vector<GLfloat>> cachePosition;
	static std::weak_ptr<std::vector<GLfloat>> cacheColor;
	static std::weak_ptr<std::vector<GLuint>> cacheEbo;
};