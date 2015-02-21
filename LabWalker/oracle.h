#pragma once
#include <functional>
#include <iostream>
#include <map>
#include <vector>
#include <list>
#include "global_types.h"


typedef std::map <std::string, double> mapSD;

class TOperator
{
public:
	void setReceivedCallBack(std::function<void(responce)>)
	{

	}
};
class Oracle
{
private:
	mapSD			m_branch;
	int				m_movementToexit;
	bool			m_isUpdated;
	TGameData*		m_gameData;
	TOperator*		m_operator;
public:
	Oracle();
	void PackageReceiveCallBack(const responce&);// bind 
	int getData();
	int analysisRating();
	void doMovement();
	bool isEfectiveMovement();
};
