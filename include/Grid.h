#ifndef GRID_H_
#define GRID_H_

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "Square.h"

using std::vector;

class Ship;

class Grid
{
private:
	using Grid1D = vector<Square*>;
	using Grid2D = vector<Grid1D>;

	Grid2D grid2D{};
	
	const int HEIGHT = 10;
	const int WIDTH = 10;
	
public:
	Grid();
	char getInfo(int x, int y);
	int getShip(int x, int y);
	Square *getSquare(int x, int y);
	bool areAllSunk();
	void placeShip(int x, int y, int funnels);
	~Grid();
};


#endif // GRID_H_