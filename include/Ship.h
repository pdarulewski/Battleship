#ifndef SHIP_H_
#define SHIP_H_

#include <string>
#include <vector>

#include "Grid.h"

class Ship
{
protected:
	int size;
	int shots;
	int range;
	int waiting;

public:
	bool isInRange(Ship* myShip, Grid *playerGrid, int x, int y);

	virtual int getShots() = 0;
	virtual int getSize() = 0;
	virtual int getRange() = 0;
	virtual int getWaiting() = 0;
	virtual void pause() = 0;
	virtual void subtractWaiting() = 0;
	virtual ~Ship();
};

#endif // SHIP_H_