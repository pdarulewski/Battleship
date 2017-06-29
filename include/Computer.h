
#ifndef COMPUTER_H_
#define COMPUTER_H_

#include "Player.h"
#include "Strategy.h"
#include "Greedy.h"
#include "Random.h"
#include "Ship.h"

#include <cstdlib>
#include <ctime>
#include <vector>

using std::vector;
using std::string;

class Computer :
	public Player
{
private:
	Grid *playerGrid;

	string name;
	vector<Ship*> ships;

	Strategy *choiceStrategy;
	int strategy;
public:
	Computer(string strategy, string name);
	string getName();
	Grid *getGrid();
	Ship *pickShip(int funnel);
	Ship *chooseShip(int funnel);
	bool checkSurrounding(int x, int y, int type);
	void placeShips();
	bool noPlaceToShoot();
	int getStrategy();
	int chooseTarget(Grid *playerGrid, Grid* opponentGrid);
	bool shootAgain(Grid *opponentGrid, int funnel);
	~Computer();
};

#endif // COMPUTER_H_