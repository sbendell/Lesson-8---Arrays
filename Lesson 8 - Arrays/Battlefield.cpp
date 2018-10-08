#include "stdafx.h"
#include "Battlefield.h"
#include <iostream>


Battlefield::Battlefield(int width, int height, int shipAmount, int turncount)
{
	turnCount = turncount;
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

void Battlefield::ProgressGame() {
	while (remainingTurns() > 0) {
		int x;
		int y;

		cout << "Take a shot! Guess X: \n";
		cin >> x;
		cout << "Guess Y: \n";
		cin >> y;

		for (int i = 0; i < ships.size; i++)
		{
			if ((x >= ships[i]->get_ship_position().first && x < ships[i]->get_ship_size().first) &&
				y >= ships[i]->get_ship_position().second && y < ships[i]->get_ship_size().second) {
				shotAttempts.push_back(make_pair(make_pair(x, y), '+'));
				cout << "You hit a ship!\n";
			}
			else {
				shotAttempts.push_back(make_pair(make_pair(x, y), '-'));
				cout << "You missed!\n";
			}
		}
	}
}

int Battlefield::remainingTurns() const {
	return turnCount;
}

Battlefield::~Battlefield()
{
	for (Battleship* ship : ships)
	{
		delete ship;
	}
}
