#pragma once
#include <functional>
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
std::string FirstDirLetter[eTotal] = {"N","S","W", "E"};
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
	void 
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
