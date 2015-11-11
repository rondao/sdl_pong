/*
* FPS.h
*
*  Created on: 10/11/2015
*      Author: rafael.rondao
*/

#pragma once

#include <SDL2/SDL.h>

class GameTime
{
public:
	GameTime(unsigned int ups);
	virtual ~GameTime();

private:
	unsigned int ups = 0;
	unsigned int timeNextUpdate = 0;
	const unsigned int UPDATE_TIME;

public:
	bool hasUpdateTimePassed();
	void advanceNextUpdateTime();
	void reset();
};