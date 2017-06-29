#ifndef HUMAN_H_
#define HUMAN_H_

#include "Player.h"
#include <string>
using std::string;

class PlayerInterface;
class Computer;

class Human :
	public Player
{
private:
	string name = "Player 1";
	Grid *playerGrid;
	vector<Ship*> ships;
	PlayerInterface *iface;
	Strategy *choiceStrategy;

public:
	Human();
	string getName();
	Grid *getGrid();
	Ship *chooseShip(int i);
	void placeShips();
	int getStrategy() { return 0; }
	bool noPlaceToShoot();
	int chooseTarget(Grid *playerGrid, Grid *opponentGrid);
	bool shootAgain(Grid *opponentGrid, int funnel);

	
	~Human();
};

#endif // HUMAN_H_

