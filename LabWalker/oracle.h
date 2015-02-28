#pragma once

#include <functional>
#include <iostream>
#include <map>
#include <vector>
#include <list>
#include "global_types.h"
#include "game_data.h"

typedef std::map <std::string, double> mapSD;

std::string FirstDirLetter[eTotal] = { "N", "S", "W", "E" };
EDirections Opposite[eTotal] = { eSouth, eNorth, eEast, eWest };

typedef std::map <std::string, double> mapSD;

class TOperator
{
public:
	void setReceivedCallBack(std::function<void(Responce)>)
	{

	}
};

class Oracle
{
private:
	mapSD					m_branch;
	int						m_movementToexit;
	bool					m_isUpdated;
	unsigned				m_MovementCount;
	TGameData*				m_gameData;
	TOperator*				m_operator;
	int						m_randcnt;
	bool					m_passed[eTotal];
	EDirections				m_LastDirection;
public:
	Oracle();
	void BrainWork();
	void PackageReceiveCallBack(const Responce&);// bind 
	int getData();
	void analysisRating(const Responce&);
	void doMovement(const Responce&);
	bool isEfectiveMovement(const Responce&);
	void doRandomMove(const Responce&);
	bool isMovePossibly(const Responce&, int);
	bool isPassed(const Responce& resp);
};

