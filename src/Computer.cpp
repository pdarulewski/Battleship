#include "Computer.h"
#include "Strategy.h"
#include "Greedy.h"
#include "Random.h"
#include "Square.h"
#include "GridInterface.h"
#include "Grid.h"
using namespace std;


Computer::Computer(string strategy , string name) : name(name)
{
	Grid *computerGrid = new Grid();
	playerGrid = computerGrid;

	string g = "greedy";
	string r = "random";

	if (g.compare(strategy) == 0)
	{
		choiceStrategy = new Greedy();
		strategy = 1;
	}

	if (r.compare(strategy) == 0)
	{
		choiceStrategy = new Random();
		strategy = 2;
	}

	Ship* one = new SingleFunnel();
	Ship* two = new MultipleFunnel(2); 
	Ship* three = new MultipleFunnel(3);

	this->ships.push_back(one);
	this->ships.push_back(two);
	this->ships.push_back(three);
}

string Computer::getName()
{
	return name;
}

Grid* Computer::getGrid()
{
	return playerGrid;
}

bool Computer::checkSurrounding(int x, int y, int type)
{
	if (x == 0 && y == 0)
	{
		for (int i = x; i < x + 2; i++)
			for (int j = y; j < y + 2; j++)
			{
				if (playerGrid->getShip(i, j) == type)
					return true;
			}
		return false;
	}
	if (x == 0 && y > 0 && y + 1 < 10)
	{
		for (int i = x; i < x + 2; i++)
			for (int j = y - 1; j < y + 2; j++)
			{
				if (playerGrid->getShip(i, j) == type)
					return true;
			}
		return false;
	}
	if (x == 9 && y == 0)
	{
		for (int i = x - 1; i < x + 1; i++)
			for (int j = y; j < y + 2; j++)
			{
				if (playerGrid->getShip(i, j) == type)
					return true;
			}
		return false;
	}
	if (x == 9 && y == 9)
	{
		for (int i = x - 1; i < x + 1; i++)
			for (int j = y - 1; j < y + 1; j++)
			{
				if (playerGrid->getShip(i, j) == type)
					return true;
			}
		return false;
	}
	if (y == 0 && x > 0 && x + 1 < 10)
	{
		for (int i = x - 1; i < x + 2; i++)
			for (int j = y; j < y + 2; j++)
			{
				if (playerGrid->getShip(i, j) == type)
					return true;
			}
		return false;
	}
	if (x == 9 && y > 0 && y + 1 < 10)
	{
		for (int i = x - 1; i < x + 1; i++)
			for (int j = y - 1; j < y + 2; j++)
			{
				if (playerGrid->getShip(i, j) == type)
					return true;
			}
		return false;
	}
	if (y == 9 && x > 0 && x + 1 < 10)
	{
		for (int i = x - 1; i < x + 2; i++)
			for (int j = y - 1; j < y + 1; j++)
			{
				if (playerGrid->getShip(i, j) == type)
					return true;
			}
		return false;
	}
	if (y == 9 && x == 0)
	{
		for (int i = x; i < x + 2; i++)
			for (int j = y - 1; j < y + 1; j++)
			{
				if (playerGrid->getShip(i, j) == type)
					return true;
			}
		return false;
	}
	else //(x > 0 && y > 0 && x + 1 < 10 && y + 1 < 10)
	{
		for (int i = x-1; i < x+2; i++)
		{
			for (int j = y-1; j < y+2; j++)
			{
				if (playerGrid->getShip(i, j) == type)
					return true;
			}
		}
		return false;
	}
}


void Computer::placeShips()
{
	struct { int x = 0;  int y = 0; } one;
	struct { int x1 = 0;  int y1 = 0; int x2 = 0;  int y2 = 0; } two;
	struct { int x1 = 0; int y1 = 0; int x2 = 0;  int y2 = 0; int x3 = 0;  int y3 = 0; } three;

	//===========================
	//3 funnel
	three.x1 = rand() % 10;
	three.y1 = rand() % 10;

	int direction = rand() % 2 + 1; //1 is horizontal, 2 is vertical 
	if (direction == 1)
	{
		int dir2 = rand() % 2 + 1; //1 to the left, 2 to the right
		if (dir2 == 1)
		{
			if (three.x1 > 0) { three.x2 = three.x1 - 1; three.y2 = three.y1; }
			else { three.x2 = three.x1 + 1; three.y2 = three.y1; }
		}
		else
		{
			if (three.x1 + 1 < 9) { three.x2 = three.x1 + 1; three.y2 = three.y1; }
			else { three.x2 = three.x1 - 1; three.y2 = three.y1; }
		}
	}
	else
	{
		int dir2 = rand() % 2 + 1; //1 to the up, 2 to the down
		if (dir2 == 1)
		{
			if (three.y1 > 0) { three.x2 = three.x1; three.y2 = three.y1 - 1; }
			else { three.x2 = three.x1; three.y2 = three.y1 + 1; }
		}
		else
		{
			if (three.y1 + 1 < 9) { three.x2 = three.x1; three.y2 = three.y1 + 1; }
			else { three.x2 = three.x1; three.y2 = three.y1 - 1; }
		}
	}
	if (three.x1 == three.x2 && three.y1 > three.y2)
	{
		if (three.y2 > 0) { three.x3 = three.x1; three.y3 = three.y2 - 1; }
		if (three.y1 + 1 < 9) { three.x3 = three.x1; three.y3 = three.y1 + 1; }
	}
	if (three.x1 == three.x2 && three.y1 < three.y2)
	{
		if (three.y1 > 0) { three.x3 = three.x1; three.y3 = three.y1 - 1; }
		if (three.y2 + 1 < 9) { three.x3 = three.x1; three.y3 = three.y2 + 1; }
	}

	if (three.y1 == three.y2 && three.x1 > three.x2)
	{
		if (three.x2 > 0) { three.x3 = three.x2 - 1; three.y3 = three.y2; }
		if (three.x1 + 1 < 9) { three.x3 = three.x1 + 1; three.y3 = three.y1; }
	}
	if (three.y1 == three.y2 && three.x1 < three.x2)
	{
		if (three.x1 > 0) { three.x3 = three.x1 - 1; three.y3 = three.y1; }
		if (three.x2 + 1 < 9) { three.x3 = three.x2 + 1; three.y3 = three.y1; }
	}
	playerGrid->placeShip(three.x1, three.y1, 3);
	playerGrid->placeShip(three.x2, three.y2, 3);
	playerGrid->placeShip(three.x3, three.y3, 3);

	//============================
	//2 funnel
	two.x1 = rand() % 10;
	two.y1 = rand() % 10;
	while (checkSurrounding(two.x1, two.y1, 3))
	{
		two.x1 = rand() % 10;
		two.y1 = rand() % 10;
	}
	do
	{
		int direction = rand() % 2 + 1; //1 is horizontal, 2 is vertical 
		if (direction == 1)
		{
			int dir2 = rand() % 2 + 1; //1 to the left, 2 to the right
			if (dir2 == 1)
			{
				if (two.x1 > 0) { two.x2 = two.x1 - 1; two.y2 = two.y1; }
				else { two.x2 = two.x1 + 1; two.y2 = two.y1; }
			}
			else
			{
				if (two.x1 + 1 < 10) { two.x2 = two.x1 + 1; two.y2 = two.y1; }
				else { two.x2 = two.x1 - 1; two.y2 = two.y1; }
			}
		}
		else
		{
			int dir2 = rand() % 2 + 1; //1 to the up, 2 to the down
			if (dir2 == 1)
			{
				if (two.y1 > 0) { two.x2 = two.x1; two.y2 = two.y1 - 1; }
				else { two.x2 = two.x1; two.y2 = two.y1 + 1; }
			}
			else
			{
				if (two.y1 + 1 < 9) { two.x2 = two.x1; two.y2 = two.y1 + 1; }
				else { two.x2 = two.x1; two.y2 = two.y1 - 1; }
			}
		}
	} while (checkSurrounding(two.x2, two.y2, 3));
	playerGrid->placeShip(two.x1, two.y1, 2);
	playerGrid->placeShip(two.x2, two.y2, 2);


	//===========================
	// 1 funnel
rrr:
	one.x = rand() % 10;
	one.y = rand() % 10;
	while (checkSurrounding(one.x, one.y, 3))
	{
		one.x = rand() % 10;
		one.y = rand() % 10;
	}
	if (checkSurrounding(one.x, one.y, 2))
		goto rrr;
	playerGrid->placeShip(one.x, one.y, 1);

}

Ship * Computer::pickShip(int funnel)
{
	funnel = choiceStrategy->choosing(ships);
	return ships[funnel - 1];
}

Ship * Computer::chooseShip(int funnel)
{
	return ships[funnel - 1];
}

int Computer::chooseTarget(Grid *playerGrid, Grid *opponentGrid)
{
	int coordinates[2];

	while (true)
	{
		int temp = choiceStrategy->choosing(ships);
		if (chooseShip(temp)->getWaiting() <= 0 && isShipAvalaible(temp, playerGrid) == true)
		{
			coordinates[0] = rand() % 10;
			coordinates[1] = rand() % 10;
			if (opponentGrid->getInfo(coordinates[0], coordinates[1]) != 'M' && opponentGrid->getInfo(coordinates[0], coordinates[1]) != 'X')
			{
				if (chooseShip(temp)->isInRange(chooseShip(temp), playerGrid, coordinates[0], coordinates[1]))
				{
					shoot(chooseShip(temp), playerGrid, opponentGrid, coordinates[0], coordinates[1]);
					chooseShip(2)->subtractWaiting();
					chooseShip(3)->subtractWaiting();
					return temp;
				}
			}
		}
	}
}

bool Computer::shootAgain(Grid *opponentGrid, int funnel) 
{ 
	/*while (true)
	{
		if (opponentGrid->getInfo(coordinates[0], coordinates[1]) != 'M' && opponentGrid->getInfo(coordinates[0], coordinates[1]) != 'X')
		{
			if (chooseShip(funnel)->isInRange(chooseShip(funnel), playerGrid, coordinates[0], coordinates[1]))
			{
				shoot(chooseShip(funnel), playerGrid, opponentGrid, coordinates[0], coordinates[1]);
				chooseShip(funnel)->pause();
				return true;
			}
		}
	}*/
	return true;
}

int Computer::getStrategy()
{
	return strategy;
}

bool Computer::noPlaceToShoot()
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


Computer::~Computer()
{
	delete choiceStrategy;
	delete playerGrid;
	this->ships.erase(this->ships.begin(), this->ships.end());
}
