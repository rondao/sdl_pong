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
	unsigned int ups;
	unsigned int timeNextUpdate;
	const unsigned int UPDATE_TIME;

public:
	bool hasUpdateTimePassed();
	float normFrameTimeDiff();
	void advanceNextUpdateTime();
	void reset();
};