#include "stdafx.h"
#include "Battleship.h"
#include <iostream>

using namespace std;

Battleship::Battleship(int spawnPosX, int spawnPosY, int spawnSizeX, int spawnSizeY):
	shipPosition(spawnPosX, spawnPosY),
	shipSize(spawnSizeX, spawnSizeY){
	for (int x = spawnPosX; x < spawnPosX + spawnSizeX; x++)
	{
		for (int y = spawnPosY; y < spawnPosY + spawnSizeY; y++)
		{
			hitPoints.push_back(make_pair(make_pair(x, y), false));
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
		if (i->first.first == hitX && i->first.second == hitY) {
			i->second = true;
		}
	}
}

bool Battleship::IsDead() {
	int counter = 0;
	for (auto hp : hitPoints)
	{
		if (hp.second) {
			counter++;
		}
	}
	if (counter != hitPoints.size())
		return false;
	else
		return true;
}

Battleship::~Battleship()
{
}
