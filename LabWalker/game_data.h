#ifndef GAME_DATA_H
#define GAME_DATA_H


enum EWorldSide
{
	eNorth,
	eSouth,
	eWest, 
	eEast,
	eTotal
};

struct TreSteps
{
	EWorldSide triple[3];
};

struct Cell
{
	Cell(){ path[0] = 0; mPassedTimes = 0; };
	Cell *path[eTotal];
	int mPassedTimes;
};


class GameData
{
public:

	int GetPathUnknownStepsCount(TreSteps iSteps)
	{
		int result = 3;
		Cell * temp_cell_ptr;
		if (temp_cell_ptr = current_player_cell->path[iSteps.triple[0]])
		{
			if (0 != temp_cell_ptr->mPassedTimes)
			{
				if (temp_cell_ptr = temp_cell_ptr->path[iSteps.triple[1]])
				{
					if (0 != temp_cell_ptr->mPassedTimes)
					{
						if (temp_cell_ptr = temp_cell_ptr->path[iSteps.triple[2]])
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
private:
	Cell *current_player_cell;

};





#endif
