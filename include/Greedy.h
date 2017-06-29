#ifndef GREEDY_H_
#define GREEDY_H_

#include "Strategy.h"
//#include "Computer.h"

class Greedy :
	public Strategy
{
public:
	int choosing(vector<Ship*> ships) override;
};

#endif // GREEDY_H_