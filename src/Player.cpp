#include "Player.h"

#include <cstdlib>

Player::Player()
{
}

bool Player::checkPosition(int temp[12])
{
	if (abs(temp[2] - temp[4]) > 1 || abs(temp[3] - temp[5]) > 1)
		return false;

	if (abs(temp[6] - temp[8]) > 1 || abs(temp[7] - temp[9]) > 1)
		return false;

	if (abs(temp[8] - temp[10]) > 1 || abs(temp[9] - temp[11]) > 1)
		return false;

	if (abs(temp[0] - temp[2]) <= 1 && abs(temp[1] - temp[3]) <= 1) //between 1 and 1st 2 funnel
		return false;

	if (abs(temp[0] - temp[4]) <= 1 && abs(temp[1] - temp[5]) <= 1) //between 1 and 2nd 2 funnel
		return false;

	if (abs(temp[0] - temp[6]) <= 1 && abs(temp[1] - temp[7]) <= 1) //between 1 and 1st 3 funnel
		return false;

	if (abs(temp[0] - temp[8]) <= 1 && abs(temp[1] - temp[9]) <= 1) //between 1 and 2nd 3 funnel
		return false;

	if (abs(temp[0] - temp[10]) <= 1 && abs(temp[1] - temp[11]) <= 1) //between 1 and 3rd 3 funnel
		return false;

	if (abs(temp[2] - temp[6]) <= 1 && abs(temp[3] - temp[7]) <= 1) //between 2 and 1st 3 funnel
		return false;

	if (abs(temp[2] - temp[8]) <= 1 && abs(temp[3] - temp[9]) <= 1) //between 2 and 2nd 3 funnel
		return false;

	if (abs(temp[2] - temp[10]) <= 1 && abs(temp[3] - temp[11]) <= 1) //between 2 and 3rd 3 funnel
		return false;

	if (abs(temp[4] - temp[6]) <= 1 && abs(temp[5] - temp[7]) <= 1) //between 2 and 1st 3 funnel
		return false;

	if (abs(temp[4] - temp[8]) <= 1 && abs(temp[5] - temp[9]) <= 1) //between 2 and 2nd 3 funnel
		return false;

	if (abs(temp[4] - temp[10]) <= 1 && abs(temp[5] - temp[11]) <= 1) //between 2 and 3rd 3 funnel
		return false;

	if (abs(temp[7] - temp[9]) == 1 || abs(temp[9] - temp[11]) == 1)
		if (temp[6] != temp[8] || temp[6] != temp[10] || temp[8] != temp[10])
			return false;

	if (abs(temp[6] - temp[8]) == 1 || abs(temp[8] - temp[10]) == 1)
		if (temp[7] != temp[9] || temp[7] != temp[11] || temp[9] != temp[11])
			return false;

	return true;
}

void Player::shoot(Ship* myShip, Grid *playerGrid, Grid *opponentGrid, int x, int y)
{
	if (opponentGrid->getShip(x, y) == 0)
	{
		opponentGrid->getSquare(x, y)->markMiss();
		iface->missAnnouncement();
	}

	if (opponentGrid->getShip(x, y) == 1)
	{
		opponentGrid->getSquare(x, y)->markHit();
		iface->hitAndSunk();
	}

	if (opponentGrid->getShip(x, y) == 2)
	{
		opponentGrid->getSquare(x, y)->markHit();

		int counter = 0;
		for (auto i = 0; i < 10; i++)
			for (auto j = 0; j < 10; j++)
				if (opponentGrid->getShip(i, j) == 2) counter++;

		if (counter == 2)
			iface->hitAndSunk();

		else iface->hitAnnouncement();
	}
	if (opponentGrid->getShip(x, y) == 3)
	{
		opponentGrid->getSquare(x, y)->markHit();

		int counter = 0;
		for (auto i = 0; i < 10; i++)
			for (auto j = 0; j < 10; j++)
				if (opponentGrid->getShip(i, j) == 3) counter++;

		if (counter == 3)
			iface->hitAndSunk();

		else iface->hitAnnouncement();
	}

	
}

bool Player::isAlive(Grid *playerGrid)
{
	return playerGrid->areAllSunk();
}

bool Player::isShipAvalaible(int funnel, Grid *playerGrid)
{
	for (auto i = 0; i < 10; i++)
		for (auto j = 0; j < 10; j++)
			if (playerGrid->getShip(i, j) == funnel)
				return true;
	return false;
}

Player::~Player()
{

}
