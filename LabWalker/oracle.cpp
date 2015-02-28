#include "stdafx.h"	

#include "oracle.h"
#include <time.h>
#define MAX_RANDOM_STEPS 3

enum rating
{
	negative = -1,
	neutral = 0,
	good = 1,
	verygood = 2,
	great = 3
};

Oracle::Oracle() :m_branch(NULL, NULL), m_movementToexit(0), m_MovementCount(NULL)
{
	m_passed[eTotal] = { false };
	using namespace std::placeholders;
	m_gameData = new TGameData;
	m_operator = new TOperator;
	m_operator->setReceivedCallBack(std::bind(&Oracle::PackageReceiveCallBack, this, _1));
	for (int i = 0; i < eTotal; i++)
	{
		for (int j = 0; j < eTotal; j++)
		{
			for (int k = 0; k < eTotal; k++)
			{
				std::string tmp;
				tmp.append(FirstDirLetter[i]);
				tmp.append(FirstDirLetter[j]);
				tmp.append(FirstDirLetter[k]);
				if (j != Opposite[i] && k != Opposite[j])
				{
					m_branch[tmp] = 0;
				}
			}
		}
	}
};

int Oracle::getData()
{

}

void Oracle::PackageReceiveCallBack(const Responce& resp)
{
	m_isUpdated = false;
	if (resp.movementToExit >= 0)
	{
		m_isUpdated = true;
		m_movementToexit = resp.movementToExit;
	}

	if (m_isUpdated)
	{
		m_gameData->AddPosition();
	}
	doMovement(resp);
}

bool Oracle::isMovePossibly(const Responce& resp, int rnd)
{
	if (resp.awal_side[rnd] == true)
	{
		return true;
	}
}

void Oracle::doMovement(const Responce& resp)
{
	EDirections next_dir;//next direction

	if (m_MovementCount < MAX_RANDOM_STEPS)
	{
		doRandomMove(resp);
	}	
	else
	{
		analysisRating(resp);
	}
	m_MovementCount++;

	m_LastDirection = next_dir;
}

void Oracle::analysisRating(const Responce& resp)
{
	if (resp.movementToExit >= 0)
	{
	}


}

void Oracle::doRandomMove(const Responce& resp)
{
	int randomStep = 0;
	srand(time(NULL));
	bool passedCell[eTotal] = { false };
	for (int cnt = 0; cnt < eTotal; cnt++)
	{
		if (!isMovePossibly(resp, randomStep))
		{
			randomStep = rand() % eTotal;
		}
		else
		{
			
			break;
		}

	}
}

