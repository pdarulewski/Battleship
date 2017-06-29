#include "Human.h"
#include "Computer.h"
#include "PlayerInterface.h"
#include <iostream>
#include <algorithm>
using namespace std;

Human::Human()
{
	Grid *humanGrid = new Grid();
	playerGrid = humanGrid;

	Ship *one = new SingleFunnel();
	Ship *two = new MultipleFunnel(2);
	Ship *three = new MultipleFunnel(3);

	this->ships.push_back(one);
	this->ships.push_back(two);
	this->ships.push_back(three);

	PlayerInterface *iface = new PlayerInterface();
}

string Human::getName()
{
	return name;
}

Grid * Human::getGrid()
{
	return playerGrid;
}

void Human::placeShips()
{
	int *temp;

	while (true)
	{
		temp = iface->placingShips();

		if (checkPosition(temp))
		{
			playerGrid->placeShip(temp[0], temp[1], 1);
			playerGrid->placeShip(temp[2], temp[3], 2);
			playerGrid->placeShip(temp[4], temp[5], 2);
			playerGrid->placeShip(temp[6], temp[7], 3);
			playerGrid->placeShip(temp[8], temp[9], 3);
			playerGrid->placeShip(temp[10], temp[11], 3);
			break;
		}

		else
			iface->showIncorrectPositions();
	}
}

Ship * Human::chooseShip(int funnel)
{
	return ships[funnel - 1];
}

int Human::chooseTarget(Grid *playerGrid, Grid *opponentGrid)
{
	
	int *coordinates;

	while (true)
	{
		int temp = iface->choosingShip();

		if (chooseShip(temp)->getWaiting() <= 0 && isShipAvalaible(temp, playerGrid) == true)
		{
			coordinates = iface->chooseTarget();

			if (opponentGrid->getInfo(coordinates[0], coordinates[1]) != 'M' && opponentGrid->getInfo(coordinates[0], coordinates[1]) != 'X')
			{
				if (chooseShip(temp)->isInRange(chooseShip(temp), playerGrid, coordinates[0], coordinates[1]))
				{
					shoot(chooseShip(temp), playerGrid, opponentGrid, coordinates[0], coordinates[1]);
					chooseShip(2)->subtractWaiting();
					chooseShip(3)->subtractWaiting();
					return temp;
				}
				else iface->outOfRangeAnnouncement();
			}
			else iface->showShootingError();
		}
		if (chooseShip(temp)->getWaiting() > 0) iface->shipIsWaitingAnnouncement();
		if (isShipAvalaible(temp, playerGrid) == false) iface->cannotChooseShipAnnouncement();
	}
}

bool Human::shootAgain(Grid *opponentGrid, int funnel)
{
	if (iface->anotherShot())
	{
		while (true)
		{
			int *coordinates;
			coordinates = iface->chooseTarget();

			if (opponentGrid->getInfo(coordinates[0], coordinates[1]) != 'M' && opponentGrid->getInfo(coordinates[0], coordinates[1]) != 'X')
			{
				if (chooseShip(funnel)->isInRange(chooseShip(funnel), playerGrid, coordinates[0], coordinates[1]))
				{
					shoot(chooseShip(funnel), playerGrid, opponentGrid, coordinates[0], coordinates[1]);
					chooseShip(funnel)->pause();
					return true;
				}
						
				else iface->outOfRangeAnnouncement();
			}
			else iface->showShootingError();
		}
	}
	else return false;
	
}

bool Human::noPlaceToShoot()
{
	for (int a = 1; a < 4; a++)
	{
		int minX, maxX, minY, maxY;
		for (int x = 0; x < 10; x++)
			for (int y = 0; y < 10; y++)
				if (playerGrid->getShip(x, y) == a)
				{
					if (x - chooseShip(a)->getRange() < 0) minX = 0;
					else minX = x - chooseShip(a)->getRange();

					if (x + chooseShip(a)->getRange() > 9) maxX = 10;
					else maxX = x + chooseShip(a)->getRange();

					if (y - chooseShip(a)->getRange() < 0) minY = 0;
					else minY = y - chooseShip(a)->getRange();

					if (y + chooseShip(a)->getRange() > 9) maxY = 10;
					else maxY = y + chooseShip(a)->getRange();
					
					for (int i = minX; i < maxX; i++)
						for (int j = minY; j < maxY; j++)
							if (playerGrid->getInfo(i, j) == ' ')
								return true;
				}
	}
	return false;
}

Human::~Human()
{
	delete playerGrid;
	delete iface;
	this->ships.erase(this->ships.begin(), this->ships.end());
}
