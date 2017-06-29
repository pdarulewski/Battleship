#ifndef STRATEGY_H_
#define STRATEGY_H_
#include "Ship.h"
//#include "Computer.h"

class Strategy
{	
public:
	virtual int choosing(vector<Ship*> ships) = 0;
};

#endif // STATEGY_H_