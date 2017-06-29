#include "GridInterface.h"

using std::cout;
using std::endl;

GridInterface::GridInterface() {}

void GridInterface::printGrids(Grid *playerGrid, Grid *opponentGrid, Player *p)
{
	char tab[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

	cout << "                                     ------------------------------------------ "<< p->getName() << " ------------------------------------------\n\n\n\n";
	cout << "                                         ------Ship grid------";
	cout << "                                          ";
	cout << "------Status grid------\n\n";
	cout << "                                          ";
	for (int i = 0; i < 10; i++) //printing the numbers - X-axis for ships
		cout << " " << i + 1;

	
	cout << "                                           ";

	for (int i = 0; i < 10; i++) //printing the numbers - x-Axis for status of squares
		cout << " " << i + 1;

	cout << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		if (i < 9)
		{
			cout << "                                        " << tab[i] << "  "; //printing the letters
			for (int j = 0; j < 10; j++)
				if (playerGrid->getShip(i, j) && playerGrid->getInfo(i, j) != 'X')
					cout << playerGrid->getShip(i, j) << " ";
				else if (playerGrid->getShip(i, j) == 0)
					cout << playerGrid->getInfo(i, j) << " ";
				else if (playerGrid->getInfo(i, j) == 'M')
					cout << playerGrid->getInfo(i, j) << " ";
				else cout << "  ";

			cout << "     ";

			cout << "                                    " << tab[i] << "  ";
			for (int j = 0; j < 10; j++)
				cout  << opponentGrid->getInfo(i, j) << " ";

			cout << endl;
		}

		else
		{
			cout << "                                        " << tab[i] << "  "; //printing the letters
			for (int j = 0; j < 10; j++)
				if (playerGrid->getShip(i, j) && playerGrid->getInfo(i, j) != 'X')
					cout << playerGrid->getShip(i, j) << " ";
				else if (playerGrid->getShip(i, j) == 0)
					cout << playerGrid->getInfo(i, j) << " ";
				else if (playerGrid->getInfo(i, j) == 'M')
					cout << playerGrid->getInfo(i, j) << " ";
				else cout << "  ";

			cout << "     ";

			cout << "                                    " << tab[i] << "  ";
			for (int j = 0; j < 10; j++)
				cout << opponentGrid->getInfo(i, j) << " ";

			cout << endl;
		}
	}
	cout << endl << endl << endl;
		
}

GridInterface::~GridInterface() {}
