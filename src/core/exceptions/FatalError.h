/*
 * InitError.h
 *
 * When this exception is launched the program got in a
 * invalid and unrecoverable state. This exception should
 * not be treated. The program will terminate and log will
 * be available at the standard output error.
 *
 *  Created on: 24/02/2014
 *      Author: Rafael Rondao
 */

#pragma once

#include <stdexcept>

class FatalError :
	public std::runtime_error
{
public:
	FatalError(void) : runtime_error("Fatal error occurred. Program will terminate.") {};
	FatalError(const char* message) : runtime_error(message) {};
	FatalError(std::string message) : runtime_error(message) {};
	virtual ~FatalError(void) {};
};

