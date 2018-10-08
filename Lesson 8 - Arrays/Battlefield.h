#pragma once
#include "Battleship.h"

using namespace std;

class Battlefield
{
public:
	Battlefield(int width, int height, int shipAmount);
	~Battlefield();
private:
	vector<Battleship*> ships;
};

