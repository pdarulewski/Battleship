#include "Square.h"
#include "GridInterface.h"

Square::Square(int x, int y, char status, int shipHere) : x(x), y(y), status(status), shipHere(shipHere)
{
}

char Square::getStatus()
{
	return status;
}

int Square::getShipPart()
{
	return shipHere;
}

void Square::setShipHere(int funnels)
{
	shipHere = funnels;
}

void Square::markHit()
{
	this->status = IS_SHOT;
	this->shipHere = IS_EMPTY;
}

void Square::markMiss()
{
	this->status = IS_MISSED;
}

void Square::setStatus(char status)
{
	this->status = status;
}

Square::~Square()
{

}