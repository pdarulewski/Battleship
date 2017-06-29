#include "Random.h"

int Random::choosing(vector<Ship*> ships)
{
	int funnel;
	while (1)
	{
		funnel = rand() % 3 + 1;
		if (ships[funnel - 1]->getWaiting() == 0)
			return funnel;
	}
}

