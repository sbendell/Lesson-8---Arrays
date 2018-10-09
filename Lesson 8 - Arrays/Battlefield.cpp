#include "stdafx.h"
#include "Battlefield.h"
#include <iostream>


Battlefield::Battlefield(int Width, int Height, int shipAmount, int turncount)
{
	srand(time(NULL));

	turnCount = turncount;
	width = Width;
	height = Height;

	for (int i = 0; i < shipAmount; i++)
	{
		int shipWidth = rand() % 4 + 1;
		int shipHeight = rand() % 3 + 1;

		int shipX = rand() % (width - (shipWidth - 1));
		int shipY = rand() % (height - (shipHeight - 1));

		Battleship* newShip = new Battleship(shipX, shipY, shipWidth, shipHeight);

		ships.push_back(newShip);
	}
}

void Battlefield::ProgressGame() {
	bool gameOver = false;
	while (remainingTurns() > 0 && !gameOver) {
		PrintBattlefield();
		cout << "\n";
		PrintBattlefieldDebug();
		int x;
		int y;

		cout << "Take a shot!\nGuess X: \n";
		cin >> x;
		cout << "Guess Y: \n";
		cin >> y;
		x--;
		y--;

		int shipsDead = 0;
		bool didHit = false;

		for (auto i = 0; i < ships.size(); i++)
		{
			if (!ships[i]->IsDead()) {
				if ((x >= ships[i]->get_ship_position().first && x < ships[i]->get_ship_position().first + ships[i]->get_ship_size().first) &&
					(y >= ships[i]->get_ship_position().second && y < ships[i]->get_ship_position().second + ships[i]->get_ship_size().second)) {
					didHit = true;
					ships[i]->hit(x, y);
				}
			}
			if (ships[i]->IsDead()) {
				shipsDead++;
			}
		}
		bool contained = false;

		for (int i = 0; i < shotAttempts.size(); i++)
		{
			if (shotAttempts[i].first.first == x && shotAttempts[i].first.second == y) {
				contained = true;
			}
		}

		if (!contained) {
			if (didHit) {
				shotAttempts.push_back(make_pair(make_pair(x, y), '+'));
				cout << "You hit a ship!\n";
			}
			else {
				shotAttempts.push_back(make_pair(make_pair(x, y), '-'));
				cout << "You missed...\n";
			}
		}
		else {
			cout << "You already shot here...\n";
		}

		if (shipsDead == ships.size()) {
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
			bool printed = false;
			for (auto shot : shotAttempts)
			{
				if (shot.first.first == x && shot.first.second == y) {
					cout << shot.second << " ";
					printed = true;
				}
			}
			if (!printed) {
				cout << "^ ";
			}
		}
		cout << "\n";
	}
}

void Battlefield::PrintBattlefieldDebug() const {
	for (int y = 0; y < width; y++)
	{
		for (int x = 0; x < height; x++)
		{
			bool printed = false;
			for (auto ship : ships)
			{
				if (!printed) {
					if ((x >= ship->get_ship_position().first && x < ship->get_ship_position().first + ship->get_ship_size().first) &&
						(y >= ship->get_ship_position().second && y < ship->get_ship_position().second + ship->get_ship_size().second)) {
						cout << "1 ";
						printed = true;
					}
				}
			}
			if (!printed) {
				cout << "^ ";
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
