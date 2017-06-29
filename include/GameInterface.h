#ifndef GAMEINTERFACE_H_
#define GAMEINTERFACE_H_

#include <string>
using std::string;

class GameInterface
{
public:
	GameInterface();
	void showingRounds(int rounds);
	void showRoundMeter(int roundCounter);
	void tourAnnouncement(string name);
	void playerWinner(string name);
	~GameInterface();
};

#endif // GAMEINTERFACE_H_