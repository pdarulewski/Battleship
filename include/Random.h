#ifndef RANDOM_H_
#define RANDOM_H_

#include "Strategy.h"
class Random :
	public Strategy
{
public:
	int choosing(vector<Ship*> ships) override;
};

#endif // RANDOM_H_