#include "game_data.h"

#include <assert.h>

int TGameData::GetPathUnknownStepsCount(TreSteps iSteps)
{
	int result = 3;
	MazeCell * temp_cell_ptr;
	if (temp_cell_ptr = current_player_cell->Sides[iSteps.triple[0]])
	{
		if (0 != temp_cell_ptr->mPassedTimes)
		{
			if (temp_cell_ptr = temp_cell_ptr->Sides[iSteps.triple[1]])
			{
				if (0 != temp_cell_ptr->mPassedTimes)
				{
					if (temp_cell_ptr = temp_cell_ptr->Sides[iSteps.triple[2]])
					{
						if (0 != temp_cell_ptr->mPassedTimes)
						{
							result = 0;
						}
						else
						{
							result = 1;
						}
					}
					else
					{
						result = 0;
					}
				}
				else
				{
					result = 2;
				}
			}
			else
			{
				result = 0;
			}
		}
	}
	else
	{
		result = 0;
	}
	return result;
}

TGameData::TGameData()
{
	current_player_cell = new MazeCell;
}

int TGameData::AddPosition(EDirections iDir, Responce iResp)
{
	if (eLookaround == iDir)
	{
		for (int c = 0; c < eTotal; c++)
		{
			if (iResp.awal_side[c] && !current_player_cell->Sides[c])
			{
				current_player_cell->Sides[c] = new MazeCell;
			}
		}
	}
	else
	{
		assert(current_player_cell->Sides[iDir]);
		current_player_cell = current_player_cell->Sides[iDir];
		for (int c = 0; c < eTotal; c++)
		{
			if (iResp.awal_side[c] && !current_player_cell->Sides[c])
			{
				current_player_cell->Sides[c] = new MazeCell;
			}
		}
	}

	if (iResp.movementToExit >= 0) current_player_cell->StepsToExit = iResp.movementToExit;
	current_player_cell->mPassedTimes++;

	return 0;
}

bool TGameData::IsPathExist(TreSteps iSteps)
{ 

	
	return false; 
}