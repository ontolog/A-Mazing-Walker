#pragma once
#include "stdafx.h"
#include <functional>

#include <list>
#include <iostream>
#include <map>
#include <vector>
#include <list>

enum EDirections
{
	eNorth, 
	eSouth,
	eWest,
	eEast,
	eTotal,
	eNone
};
std::string FirstDirLetter[eTotal] = { "N", "S", "W", "E" };
EDirections Opposite[eTotal] = { eSouth, eNorth, eEast, eWest };

typedef std::map <std::string, double> mapSD;

struct responce
{
	bool array[eTotal];
	int movementToExit;
};
class TGameData
{
public:
	void setData()
	{

	}
};
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
	mapSD					m_branch;
	int						m_movementToexit;
	bool					m_isUpdated;
	unsigned				m_MovementCount;
	TGameData*				m_gameData;
	TOperator*				m_operator;
	int						m_randcnt;
	bool					m_passed[eTotal];
	
public:
	Oracle();
	void BrainWork();
	void PackageReceiveCallBack(const responce&);// bind 
	int getData();
	void analysisRating(const responce&);
	void doMovement(const responce&);
	bool isEfectiveMovement(const responce&);
	void doRandomMove(const responce&);
	bool isMovePossibly(const responce&, int) ;
	bool isPassed(const responce& resp);
};