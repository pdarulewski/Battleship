#include "GameInterface.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

GameInterface::GameInterface()
{
}

void GameInterface::showRoundMeter(int roundCounter)
{
	cout << "\n\n                                     Round number " << roundCounter << "!\n\n";
}

void GameInterface::tourAnnouncement(string name)
{
	cout << "\n\n"<< name << " is now playing...\n\n";
}

void GameInterface::playerWinner(string name)
{
	cout << "The winner is " << name << "!\n\n";
}

void GameInterface::showingRounds(int rounds)
{
	cout << "Rounds left: " << rounds << endl;
}

GameInterface::~GameInterface()
{
}
