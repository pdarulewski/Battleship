#include "GameLogic.h"
#include "Square.h"
#include "Grid.h"
#include "GameInterface.h"

#include <iostream>
#include <fstream>

using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;

GameLogic::GameLogic(int rounds, string strategy1, int roundCounter) : rounds(rounds), roundCounter(roundCounter)
{
	this->player1 = new Human();
	this->player2 = new Computer(strategy1, "Computer");
	GameInterface *g = new GameInterface();
}

GameLogic::GameLogic(int rounds, string strategy1, string strategy2, int roundCounter) : rounds(rounds), roundCounter(roundCounter)
{
	this->player1 = new Computer(strategy1, "Computer 1");
	this->player2 = new Computer(strategy2, "Computer 2");
	GameInterface *g = new GameInterface();
}

void GameLogic::placingShips()
{
	player1->placeShips();
	player2->placeShips();
}

void GameLogic::play()
{
	//system("CLS");

	GridInterface *p1 = new GridInterface();

	while (player1->getGrid()->areAllSunk() != true && player2->getGrid()->areAllSunk() != true && roundCounter <= rounds && player1->noPlaceToShoot() && player2->noPlaceToShoot())
	{
		g->showRoundMeter(roundCounter);
		p1->printGrids(player1->getGrid(), player2->getGrid(), player1);
	//	p1->printGrids(player2->getGrid(), player1->getGrid(), player2);

		g->tourAnnouncement(player1->getName());
		int funnel = player1->chooseTarget(player1->getGrid(), player2->getGrid());
		p1->printGrids(player1->getGrid(), player2->getGrid(), player1);
		//p1->printGrids(player2->getGrid(), player1->getGrid(), player2);

		if (player1->getGrid()->areAllSunk() != true && player2->getGrid()->areAllSunk() != true && roundCounter <= rounds && player1->noPlaceToShoot() && player2->noPlaceToShoot()) //in case of computer fails after human shot
		{
			if ((funnel == 2 || funnel == 3) && player1->shootAgain(player2->getGrid(), funnel))
				p1->printGrids(player1->getGrid(), player2->getGrid(), player1);

			if (player1->getGrid()->areAllSunk() != true && player2->getGrid()->areAllSunk() != true && roundCounter <= rounds && player1->noPlaceToShoot() && player2->noPlaceToShoot())
			{
				g->tourAnnouncement(player2->getName());
				player2->chooseTarget(player2->getGrid(), player1->getGrid());
				p1->printGrids(player1->getGrid(), player2->getGrid(), player1);
			}
		}
		else break;
		roundCounter++;
		save(player1, player2);
	}
	delete p1;
	endGame();
}

void GameLogic::simulation()
{
	int roundCounter = 1;
	GridInterface *p1 = new GridInterface();
	placingShips();

	int funnel = 0;
	int funnel2 = 0;
	while (player1->getGrid()->areAllSunk() != true && player2->getGrid()->areAllSunk() != true && player1->noPlaceToShoot() && roundCounter <= rounds && player1->noPlaceToShoot() && player2->noPlaceToShoot())
	{

		g->showRoundMeter(roundCounter);
		p1->printGrids(player1->getGrid(), player2->getGrid(), player1);
		p1->printGrids(player2->getGrid(), player1->getGrid(), player2);
		g->tourAnnouncement(player1->getName());

		funnel = player1->chooseTarget(player1->getGrid(), player2->getGrid());
		if (player1->getGrid()->areAllSunk() != true && player2->getGrid()->areAllSunk() != true && roundCounter <= rounds && player1->noPlaceToShoot() && player2->noPlaceToShoot()) //in case of computer fails after human shot
		{
			if ((funnel == 2 || funnel == 3) && player1->shootAgain(player2->getGrid(), funnel))
				//p1->printGrids(player1->getGrid(), player2->getGrid(), player1);
			if ((funnel == 2 || funnel == 3) && player2->shootAgain(player1->getGrid(), funnel))
				//p1->printGrids(player2->getGrid(), player1->getGrid(), player2);

			if (player1->getGrid()->areAllSunk() != true && player2->getGrid()->areAllSunk() != true && roundCounter <= rounds && player1->noPlaceToShoot() && player2->noPlaceToShoot())
			{
				g->tourAnnouncement(player2->getName());
				player2->chooseTarget(player2->getGrid(), player1->getGrid());
				p1->printGrids(player1->getGrid(), player2->getGrid(), player1);
				p1->printGrids(player2->getGrid(), player1->getGrid(), player2);
			}
		}
		else break;
		save(player1, player2);
		roundCounter++;
	}
	delete p1;
	endGame();
}

int GameLogic::whoWon()
{
	if (player1->noPlaceToShoot()) return 2;
	if (player2->noPlaceToShoot()) return 1;
	int player1Counter = 0;
	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 10; y++)
			if (player1->getGrid()->getShip(x, y)) player1Counter++;

	int player2Counter = 0;
	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 10; y++)
			if (player2->getGrid()->getShip(x, y)) player2Counter++;

	if (player1Counter > player2Counter) return 1;
	if (player1Counter < player2Counter) return 2;
	else return -1;
}



void GameLogic::endGame()
{
	if (whoWon() == 1) g->playerWinner(player1->getName());
	if (whoWon() == 2) g->playerWinner(player2->getName());
}

void GameLogic::save(Player *player1, Player *player2)
{
	string const SaveFile("SaveFile.txt");
	ofstream f(SaveFile.c_str());

	f << roundCounter << endl;
	f << rounds << endl;
	f << player2->getStrategy() << endl;

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
			f << player1->getGrid()->getInfo(x, y);
		f << endl;
	}

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
			f << player1->getGrid()->getShip(x, y);
		f << endl;
	}

	f << player1->chooseShip(2)->getWaiting();
	f << endl;
	f << player1->chooseShip(3)->getWaiting();
	f << endl;

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
			f << player2->getGrid()->getInfo(x, y);
		f << endl;
	}

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
			f << player2->getGrid()->getShip(x, y);
		f << endl;
	}
	f << player2->chooseShip(2)->getWaiting();
	f << endl;
	f << player2->chooseShip(3)->getWaiting();
	f.close();
}

void GameLogic::load(string fileName)
{
	string temp;
	ifstream f(fileName);
	for (int x = 0; x < 3; x++) getline(f, temp);
	char a;
	int t;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			f.get(a);
			player1->getGrid()->getSquare(i, j)->setStatus(a);
		}
		f.get(a);
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			f.get(a);
			t = a - '0';
			player1->getGrid()->getSquare(i, j)->setShipHere(t);
		}
		f.get(a);
	}
	getline(f, temp);
	if (stoi(temp) > 0) player1->chooseShip(2)->pause();

	getline(f, temp);
	if (stoi(temp) > 0) player1->chooseShip(3)->pause();

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			f.get(a);
			player2->getGrid()->getSquare(i, j)->setStatus(a);
		}
		f.get(a);
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			f.get(a);
			t = a - '0';
			player2->getGrid()->getSquare(i, j)->setShipHere(t);
		}
		f.get(a);
	}
	getline(f, temp);
	if (stoi(temp) > 0) player2->chooseShip(2)->pause();

	getline(f, temp);
	if (stoi(temp) > 0) player2->chooseShip(3)->pause();

	f.close();
	play();
}

GameLogic::~GameLogic()
{
	delete g;
	delete player1;
	delete player2;
}