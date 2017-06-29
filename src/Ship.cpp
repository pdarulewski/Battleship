#include <iostream>
#include <string>
#include <vector>
#include "Ship.h"
#include "Player.h"

bool Ship::isInRange(Ship* myShip, Grid *playerGrid, int x, int y)
{
	bool flag = true;
	int range = myShip->getRange();

	for (auto i = 0; i < 10; i++)
		for (auto j = 0; j < 10; j++)
			if (playerGrid->getShip(i, j) == myShip->getSize())
				if (abs(x - i) <= range && abs(y - j) <= range)
					return true;
				else 
					flag = false;

	return flag;
}

Ship::~Ship()
{

}
