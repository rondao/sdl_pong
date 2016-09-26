#pragma once

#include <gl/glew.h>
#include <memory>
#include <vector>

#include "../../libs/glm/glm.hpp"

#include "../entities/Rect.h"
#include "../entities/Graphic2D.h"
#include "../shaders/Shader.h"

class BBRenderer : public Graphic2D
{
public:
	void renderRect(Rect rect, const glm::mat4 &transformMatrix);
};