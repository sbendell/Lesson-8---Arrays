#include "stdafx.h"
#include "Battlefield.h"


Battlefield::Battlefield(int width, int height, int shipAmount)
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			for (int i = 0; i < shipAmount; i++)
			{
				int shipWidth = rand() % 6 + 1;
				int shipHeight = rand() % 6 + 1;

				int shipX = width - (shipWidth - 1);
				int shipY = height - (shipHeight - 1);

				Battleship* newShip = new Battleship(shipX, shipY, shipWidth, shipHeight);

				ships.push_back(newShip);
			}
		}
	}
}


Battlefield::~Battlefield()
{
}
