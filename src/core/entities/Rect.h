/*
* Rect.h
*
*  Created on: 14/11/2015
*      Author: rafael.rondao
*/

#pragma once

#include <cmath>

#include "../../libs/glm/glm.hpp"
#include "../../libs/glm/gtc/type_ptr.hpp"

class Rect
{
	friend class Graphic2D;
public:
	Rect();
	virtual ~Rect();

private:
	glm::vec2 origin;
	float width;
	float height;

public:
	bool checkCollision(const Rect& other);
};