#include <iostream>
#include <string>
#include <vector>
#include "Grid.h"
#include "Square.h"
#include "Human.h"
using std::cout;
using std::endl;
Grid::Grid()
{	
	Grid2D grid2D(10);
	for (auto i = 0; i < WIDTH; i++)
	{
		Grid1D grid1D(10);
		for (auto j = 0; j < HEIGHT; j++)
			grid1D[j] = new Square(i, j, ' ', 0);

		grid2D[i] = grid1D;
	}
	this->grid2D = grid2D;
}

char Grid::getInfo(int x, int y)
{
	return grid2D[x][y]->getStatus();
}

int Grid::getShip(int x, int y)
{
	return grid2D[x][y]->getShipPart();
}

Square * Grid::getSquare(int x, int y)
{
	return grid2D[x][y];
}

bool Grid::areAllSunk()
{
	for (auto i = 0; i < WIDTH; i++)
		for (auto j = 0; j < HEIGHT; j++)
			if (grid2D[i][j]->getShipPart())
				return false;
	return true;
}

void Grid::placeShip(int x, int y, int funnels)
{
	grid2D[x][y]->setShipHere(funnels);
}

Grid::~Grid()
{
}