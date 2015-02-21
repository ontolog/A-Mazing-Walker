#ifndef GLOBAL_TYPES_H
#define GLOBAL_TYPES_H

#include <string>

struct Responce
{
	bool awal_side[eTotal];
	int movementToExit;
};


enum EDirections
{
	eNorth,
	eSouth,
	eWest,
	eEast,
	eTotal,
	eLookaround
};

std::string FirstDirLetter[eTotal] = { "N", "S", "W", "E" };

EDirections Opposite[eTotal] = { eSouth, eNorth, eEast, eWest };











#endif
