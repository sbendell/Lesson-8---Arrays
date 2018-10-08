#pragma once
#include <random>
#include <time.h>

class Battleship
{
public:
	Battleship(pair<int, int> spawnPos, pair<int, int> spawnSize);
	~Battleship();
private:
	pair<int, int> shipPosition;
	pair<int, int> shipSize;
};

