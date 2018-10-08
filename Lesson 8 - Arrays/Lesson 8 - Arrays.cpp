// Lesson 8 - Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Battleship.h"

using namespace std;

float calc_avg(const int* arr, const int val) {
	int sum = 0;

	for (int i = 0; i < val; ++i) {
		sum += arr[i];
	}

	return (sum / (float)val);
}

void Print_Array(char charArr[]){
	for (int i = 0; i < 11; i++) {
		cout << charArr[i];
	}
}

void PrintBattleship(bool** battleship, vector<pair<int, int>> hitLocs, int attempts) {
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			bool printed = false;
			for (int i = 0; i < attempts; i++)
			{
				if (hitLocs[i].first == x && hitLocs[i].second == y) {
					printed = true;
					if (battleship[hitLocs[i].second][hitLocs[i].first]) {
						cout << "X ";
					}
					else {
						cout << "x ";
					}
				}
			}
			if (!printed) {
				cout << battleship[y][x] << " ";
			}
		}
		cout << "\n";
	}
}

int main()
{
	srand(time(NULL));

	int attempts = 0;
	vector<pair<int, int>> hitLocations;
	int xGuess;
	int yGuess;
	bool hit = false;

	while (attempts < 8 && hit == false) {
		cout << "Please guess x position.\n";
		cin >> xGuess;
		cout << "Please guess y position\n";
		cin >> yGuess;

		hitLocations.push_back(pair<int, int>(xGuess - 1, yGuess - 1));

		if (battleship[yGuess - 1][xGuess - 1]) {
			hit = true;
		}
		else {
			cout << "You missed the ship.\n";
		}
		attempts++;
	}

	if (hit) {
		cout << "You hit the ship!\n";
	}
	else {
		cout << "You did not hit the ship.\n";
	}

	PrintBattleship(battleship, hitLocations, attempts);

	for (int i = 0; i < 8; i++)
	{
		delete[] battleship[i];
	}

	/*const int CONST_VALUE = 3;
	float ave;

	// stack based 1-d arrays
	int array_nums[CONST_VALUE] = { 2, 4, 5 };

	// print out the first element
	cout << "value at index 0 is " << array_nums[0] << "\n";

	//stack based 2-d arrays
	char naughts_n_xs[3][3];

	// set the middle square to x
	naughts_n_xs[1][1] = 'X';

	//arrays on the heap 1-d
	int* sum = new int[CONST_VALUE];

	for (int i = 0; i < CONST_VALUE; ++i)
	{
		cout << "enter a value...\n";
		cin >> sum[i];
	}

	ave = calc_avg(sum, CONST_VALUE);

	cout << "the average is " << ave << "\n";

	delete[] sum;

	char myName[11] = { 'S', 'a', 'm', ' ', 'B', 'e', 'n', 'd', 'e', 'l', 'l' };

	char* firstName = new char[3] { NULL, NULL, NULL};
	char* lastName = new char[7] { NULL, NULL, NULL, NULL, NULL, NULL, NULL };

	for (int i = 0; i < 11; i++)
	{
		if (i < 3) {
			*firstName = myName[i];
			cout << *firstName;
			firstName++;
		}
		else if (i > 3) {
			*lastName = myName[i];
			cout << *lastName;
			lastName++;
		}
	}

	Print_Array(myName);*/

	int a = 2;

	cin >> a;

	return 0;
}