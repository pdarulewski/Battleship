#ifndef GRIDINTERFACE_H_
#define GRIDINTERFACE_H_

#include "Grid.h"
#include "Player.h"
#include "Computer.h"
#include "Human.h"

#include <iostream>

class GridInterface
{
public:
	GridInterface();
	void printGrids(Grid *playerGrid, Grid *opponentGrid, Player *p);
	~GridInterface();
};

#endif // GRIDINTERFACE_H_