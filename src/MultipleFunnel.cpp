#include "MultipleFunnel.h"



MultipleFunnel::MultipleFunnel()
{
}

MultipleFunnel::MultipleFunnel(int size) : shots(2), size(size), waiting(0)
{
	if (size == 2)
		this->range = 3;

	if (size == 3)
		this->range = 4;
}

int MultipleFunnel::getShots()
{
	return shots;
}

int MultipleFunnel::getRange()
{
	return range;
}

int MultipleFunnel::getSize()
{
	return size;
}

int MultipleFunnel::getWaiting()
{
	return this->waiting;
}

void MultipleFunnel::subtractWaiting()
{
	this->waiting -= 1;
	if (this->waiting < 0)
		this->waiting = 0;
}

void MultipleFunnel::pause()
{
	this->waiting = 1;
}

MultipleFunnel::~MultipleFunnel()
{
}
