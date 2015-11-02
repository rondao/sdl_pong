/*
* Data2D.h
*
*  Created on: 27/10/2015
*      Author: Rafael Rondao
*/

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <gl/glew.h>

#include "../../game/characters/Paddle.h"
#include "../exceptions/FatalError.h"

class Paddle;
void loadFromFile(const char* filename, Paddle* paddle);