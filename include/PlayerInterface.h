#ifndef PLAYERINTERFACE_H_
#define PLAYERINTERFACE_H_

class PlayerInterface
{
private:
	const int HEIGHT = 10;
	const int WIDTH = 10;
public:
	PlayerInterface();
	int* placingShips();
	int choosingShip();
	int* chooseTarget();
	bool anotherShot();
	void showShootingError();
	void showIncorrectPositions();
	void outOfRangeAnnouncement();
	void cannotChooseShipAnnouncement();
	void shipIsWaitingAnnouncement();
	void missAnnouncement();
	void hitAnnouncement();
	void hitAndSunk();
	~PlayerInterface();
};

#endif // PLAYERINTERFACE_H_