#include "SingleFunnel.h"



SingleFunnel::SingleFunnel() : shots(1), range(2), size(1), waiting(0)
{
}

int SingleFunnel::getShots()
{
	return shots;
}

int SingleFunnel::getRange()
{
	return range;
}

int SingleFunnel::getSize()
{
	return size;
}

void SingleFunnel::pause()
{

}

int SingleFunnel::getWaiting()
{
	return 0;
}

void SingleFunnel::subtractWaiting()
{
}

SingleFunnel::~SingleFunnel()
{
}
