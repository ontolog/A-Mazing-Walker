#include"Oracle.h"

Oracle::Oracle() :m_branch(NULL,NULL), m_movementToexit(0)
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

void Oracle::PackageReceiveCallBack(const responce& resp)
{
	m_isUpdated = false;
	if (resp.movementToExit >= 0)
	{
		m_isUpdated = true;
		m_movementToexit = resp.movementToExit;
	}
	doMovement();
}
void Oracle::doMovement()
{
	if (m_isUpdated)
	{
		m_gameData->setData();
	}
	analysisRating();
}
int Oracle::analysisRating()
{
		
}
