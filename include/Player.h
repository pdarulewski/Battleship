#ifndef PLAYER_H_
#define PLAYER_H_

#include "Grid.h"
#include "Ship.h"
#include "SingleFunnel.h"
#include "PlayerInterface.h"
#include "MultipleFunnel.h"
#include "Strategy.h"

#include <string>
using std::string;

class Player
{
private:
	string name;
	Grid *playerGrid;

	vector<Ship*> ships;
	PlayerInterface *iface;
	Strategy *choiceStrategy;

public:
	Player();
	virtual string getName() = 0;
	virtual Grid *getGrid() = 0;
	virtual Ship* chooseShip(int funnel) = 0;
	virtual void placeShips() = 0;
	virtual int chooseTarget(Grid *playerGrid, Grid *opponentGrid) = 0;
	virtual bool shootAgain(Grid *opponentGrid, int funnel) = 0;
	virtual int getStrategy() = 0;

	bool checkPosition(int temp[12]);
	void shoot(Ship* myShip, Grid *playerGrid, Grid *opponentGrid, int x, int y);
	virtual bool noPlaceToShoot() = 0;

	bool isAlive(Grid *playerGrid);
	bool isShipAvalaible(int funnel, Grid *playerGrid);

	virtual ~Player();
};

#endif // PLAYER_H_