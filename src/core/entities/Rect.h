/*
* Rect.h
*
*  Created on: 14/11/2015
*      Author: rafael.rondao
*/

#pragma once

#include <cmath>
#include <fstream>

#include "../../libs/glm/glm.hpp"
#include "../../libs/glm/gtc/type_ptr.hpp"

class Rect
{
public:
	Rect();
	virtual ~Rect();

private:
	glm::vec2 origin;
	float width;
	float height;

public:
	Rect applyModelMatrix(const glm::mat4 &transformMatrix);
	bool checkCollision(const Rect& other);
	void loadFromFile(std::ifstream& file);
};