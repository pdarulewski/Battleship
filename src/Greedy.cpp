#include "Greedy.h"
#include <iostream>
using namespace std;
#include "Computer.h"
#include "Ship.h"
#include <iostream>

int Greedy::choosing(vector<Ship*> ships)
{
	int funnel;
	for (int i = 3; i > 0; i--)
	{
		funnel = i;
		if (ships[i - 1]->getWaiting() == 0)
			return funnel;
	}
}
