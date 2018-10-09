#include "stdafx.h"
#include "Battlefield.h"
#include <iostream>


Battlefield::Battlefield(int Width, int Height, int shipAmount, int turncount)
{
	turnCount = turncount;
	width = Width;
	height = Height;
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
	bool gameOver = false;
	while (remainingTurns() > 0 && !gameOver) {
		PrintBattlefield();
		int x;
		int y;

		cout << "Take a shot! Guess X: \n";
		cin >> x;
		cout << "Guess Y: \n";
		cin >> y;

		int shipsDead = 0;

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

			if (ships[i]->IsDead) {
				shipsDead++;
			}
		}
		if (shipsDead == ships.size) {
			gameOver = true;
		}
	}

	if (gameOver) {
		cout << "You killed every ship!!\n";
	}
	else {
		cout << "You didnt kill every ship...\n";
	}
	PrintBattlefield();
}

int Battlefield::remainingTurns() const {
	return turnCount;
}

void Battlefield::PrintBattlefield() const {
	for (int y = 0; y < width; y++)
	{
		for (int x = 0; x < height; x++)
		{
			for (auto shot : shotAttempts)
			{
				if (shot.first.first == x && shot.first.second == y) {
					cout << shot.second << " ";
				}
				else {
					cout << "^ ";
				}
			}
		}
		cout << "\n";
	}
}

Battlefield::~Battlefield()
{
	for (Battleship* ship : ships)
	{
		delete ship;
	}
}
