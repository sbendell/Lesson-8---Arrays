#include "stdafx.h"
#include "Battleship.h"

using namespace std;

Battleship::Battleship(int spawnPosX, int spawnPosY, int spawnSizeX, int spawnSizeY):
	shipPosition(spawnPosX, spawnPosY),
	shipSize(spawnSizeX, spawnSizeY){
	for (int x = 0; x < spawnSizeX; x++)
	{
		for (int y = 0; y < spawnSizeY; y++)
		{
			hitPoints.push_back(make_pair(x, y));
		}
	}
}

Battleship::Battleship(pair<int, int> spawnPos, pair<int, int> spawnSize) :
	shipPosition(spawnPos.first, spawnPos.second),
	shipSize(spawnSize.first, spawnSize.second) {
}

pair<int, int> Battleship::get_ship_position() const {
	return shipPosition;
}

pair<int, int> Battleship::get_ship_size() const {
	return shipSize;
}

void Battleship::hit(int hitX, int hitY) {
	for (auto i = hitPoints.begin(); i != hitPoints.end(); i++)
	{
		if (i->first && i->second) {
			hitPoints.erase(i);
		}
	}
}

bool Battleship::IsDead() {
	if (hitPoints.size() > 0)
		return false;
	else
		return true;
}

Battleship::~Battleship()
{
}
