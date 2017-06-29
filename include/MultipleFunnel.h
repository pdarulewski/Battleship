#ifndef MULTIPLEFUNNEL_H_
#define MULTIPLEFUNNEL_H_

#include "Ship.h"

class MultipleFunnel :
	public Ship
{
private:
	int shots;
	int size;
	int range;
	int waiting;
public:
	MultipleFunnel();
	MultipleFunnel(int size);
	int getShots();
	int getSize();
	int getRange();
	int getWaiting();
	void pause();
	void subtractWaiting();
	~MultipleFunnel();
};

#endif // MULTIPLEFUNNEL_H_