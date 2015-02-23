#include "stdafx.h"	
#include "oracle.h"
#include <time.h>
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
void Oracle::PackageReceiveCallBack(const responce& resp)
{
	m_isUpdated = false;
	if (resp.movementToExit >= 0)
	{
		m_isUpdated = true;
		m_movementToexit = resp.movementToExit;
	}
	if (m_isUpdated)
	{
		m_gameData->setData();
	}
	m_MovementCount++;
	analysisRating(resp);
	doMovement();
}

void Oracle::doMovement()
{
	

}
void Oracle::analysisRating(const responce& resp)
{
	bool flag = false;
	if (m_MovementCount < 3)
	{
		srand(time(NULL));
		while (!flag)
		{
			m_randcnt = rand() % eTotal;

			if (resp.array[m_randcnt] == true)
			{
				flag == true;
				doMovement();
			}
		}
	}
	else
	{
	
	}
}
	
