/*
 * Main.cpp
 *
 *  Created on: 07/07/2013
 *      Author: Rafael Rondao
 */

#include <iostream>

#include <SDL2\SDL.h>

#include "core\exceptions\FatalError.h"
#include "game\Game.h"

// The main full prototype is required, because SDL overwrite
//  it with macro to make it system independent.
int main(int argc, char *argv[]) {
	try {
		Game mGame;
		mGame.execute();
	} catch (FatalError fe) {
		std::cerr << fe.what();
		return 0;
	}

	return 1;
}

