#pragma once
#include <random>
#include <time.h>

class Battleship
{
public:
	Battleship(int spawnPosX, int spawnPosY, int spawnSizeX, int spawnSizeY);
	Battleship(pair<int, int> spawnPos, pair<int, int> spawnSize);
	~Battleship();
	void hit(int hitX, int hitY);
private:
	pair<int, int> shipPosition;
	pair<int, int> shipSize;
	vector<pair<int, int>> hitPoints;
};

