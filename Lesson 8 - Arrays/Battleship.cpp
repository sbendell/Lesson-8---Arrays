#include "stdafx.h"
#include "Battleship.h"

using namespace std;

Battleship::Battleship(pair<int, int> spawnPos, pair<int, int> spawnSize):
	shipPosition(spawnPos.first, spawnPos.second),
	shipSize(spawnSize.first, spawnSize.second){
}

Battleship::~Battleship()
{
}
