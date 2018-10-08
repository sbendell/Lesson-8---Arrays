#pragma once
#include "Battleship.h"

using namespace std;

class Battlefield
{
public:
	Battlefield(int width, int height, int shipAmount, int turncount);
	~Battlefield();
	void ProgressGame();
	int remainingTurns() const;
	void PrintBattlefield() const;
private:
	vector<Battleship*> ships;
	vector<pair<pair<int, int>, char>> shotAttempts;
	int turnCount;
};

