#include "stdafx.h"
#include "Battleship.h"

Battleship::Battleship()
{
}

bool** CreateBattleship() {
	int shipAlignment = rand() % 2;
	int shipXPos;
	int shipYPos;

	bool** battleshipPosition = new bool*[8];
	for (int i = 0; i < 8; i++)
	{
		battleshipPosition[i] = new bool[8];
		for (int x = 0; x < 8; x++)
		{
			battleshipPosition[i][x] = false;
		}
	}

	if (shipAlignment == 0) {
		shipYPos = rand() % 6;
		bool* yPos1 = battleshipPosition[shipYPos];
		bool* yPos2 = battleshipPosition[shipYPos + 1];
		bool* yPos3 = battleshipPosition[shipYPos + 2];
		shipXPos = rand() % 8;
		yPos1[shipXPos] = true;
		yPos2[shipXPos] = true;
		yPos3[shipXPos] = true;
	}
	else {
		shipYPos = rand() % 8;
		bool* yPos = battleshipPosition[shipYPos];
		shipXPos = rand() % 6;
		yPos[shipXPos] = true;
		yPos[shipXPos + 1] = true;
		yPos[shipXPos + 2] = true;
	}

	return battleshipPosition;
}

Battleship::~Battleship()
{
}
