#ifndef SINGLEFUNNEL_H_
#define SINGLEFUNNEL_H_

#include "Ship.h"

class SingleFunnel :
	public Ship
{
private:
	int shots;
	int range;
	int size;
	int waiting;
public:
	SingleFunnel();
	int getShots();
	int getSize();
	int getRange();
	int getWaiting();
	void pause();
	void subtractWaiting();
	~SingleFunnel();
};

#endif // SINGLEFUNNEL_H_