#ifndef GAME_DATA_H
#define GAME_DATA_H

#include "global_types.h"

struct TreSteps
{
	EDirections triple[3];
};

struct MazeCell
{
	int mPassedTimes;
	MazeCell * Sides[eTotal];
	int StepsToExit;
	MazeCell()
	{
		mPassedTimes = 0;
		Sides[eNorth] = 0;
		Sides[eSouth] = 0;
		Sides[eWest] = 0;
		Sides[eEast] = 0;
		StepsToExit = 0;
	}
};

class TGameData
{
public:
	TGameData();
	int GetPathUnknownStepsCount(TreSteps iSteps);
	int AddPosition(EDirections iDir, Responce iResp);
	bool IsPathExist(TreSteps iSteps){ return false; }
private:
	MazeCell *current_player_cell;

};





#endif
