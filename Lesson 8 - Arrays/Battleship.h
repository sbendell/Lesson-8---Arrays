#pragma once
#include <random>
#include <time.h>

using namespace std;

class Battleship
{
public:
	Battleship(int spawnPosX, int spawnPosY, int spawnSizeX, int spawnSizeY);
	Battleship(pair<int, int> spawnPos, pair<int, int> spawnSize);
	~Battleship();
	pair<int, int> get_ship_position() const;
	pair<int, int> get_ship_size() const;
	void hit(int hitX, int hitY);
	bool IsDead();
private:
	pair<int, int> shipPosition;
	pair<int, int> shipSize;
	vector<pair<int, int>> hitPoints;
};

