/*
 * Main.cpp
 *
 *  Created on: 07/07/2013
 *      Author: Rafael Rondao
 */

#include <SDL2\SDL.h>

#include "core\Core.h"

// The main full prototype is required, because SDL overwrite
//  it with macro to make it system independent.
int main(int argc, char *argv[]) {
	Core mGame;
	return mGame.execute();
}

