#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_

#include <iostream>
#include <string>
#include <vector>

#include "Player.h"
#include "Computer.h"
#include "Human.h"
#include "GridInterface.h"
#include "GameInterface.h"
#include "Grid.h"

using std::string;

class GameLogic
{
private:
	Player *player1;
	Player *player2;
	GameInterface *g;
	int rounds;
	int roundCounter;
public:
	GameLogic(int rounds, string strategy1, int roundCounter);
	GameLogic(int rounds, string strategy1, string strategy2, int roundCounter);
	void placingShips();
	void play();
	void simulation();
	int whoWon();
	void endGame();
	void save(Player *player1, Player *player2);
	void load(string fileName);
	~GameLogic();
};

#endif // GAMELOGIC_H_