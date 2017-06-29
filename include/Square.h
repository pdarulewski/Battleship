#ifndef SQUARE_H_
#define SQUARE_H_

#include <iostream>

class Square
{
private:
	const int IS_ONE = 1;
	const int IS_TWO = 2;
	const int IS_THREE = 3;
	const char IS_MISSED = 'M';
	const char IS_SHOT = 'X';
	const char IS_EMPTY = 0;
	int shipHere;
	char status;
	int x;
	int y;
public:
	Square(int x, int y, char status, int shipHere);
	int getShipPart();
	char getStatus();
	void setShipHere(int funnels);
	void markHit();
	void markMiss();
	void setStatus(char status);
	~Square();
};

#endif // SQUARE_H_