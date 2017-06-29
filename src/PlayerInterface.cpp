#include "PlayerInterface.h"
#include "Player.h"
#include <regex>
#include <windows.h>
#include <iostream>
#include <string>
#include "Grid.h"
#include "Square.h"
using namespace std;


PlayerInterface::PlayerInterface()
{
}

int* PlayerInterface::placingShips()
{
	//system("CLS");
	cout << "You have to place 3 ships:\n"
		<< "- a Single Funnel Ship\n"
		<< "- a Double Funnel Ship\n"
		<< "- a Triple Funnel Ship\n";

	cout << "Your ships cannot overlap or touch - they have to have minimum one square free space in all directions!\n\n";

	cout << "Please, give the coordinates of placing the ships in ascending or descending order.\n"
		<< "The coordinate looks like [LETTER][NUMBER], where numbers are on X-axis and small letters are on Y-axis\n\n";

	regex pattern("([a-j])((10)|(1|2|3|4|5|6|7|8|9))");
	regex pattern10("([a-j])(10)");
	string e = "Your coordinates are wrong!\n";

	int *temp = new int[12]{};

	string funnel[3] = { "first", "second", "third" };

	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			while (true)
			{
				cout << "Please, give coordinates of the Single Funnel Ship: ";
				string data;
				cin >> data;

				if (regex_match(data, pattern))
				{
					temp[2 * i] = (data.front() - 97);
					if (regex_match(data, pattern10))
						temp[2 * i + 1] = 9;
					else temp[2 * i + 1] = data[1] - '0' - 1;
					break;
				}
				else cout << e << endl;
			}
		}

		if (i == 1)
			for (int j = 0; j < 2; j++)
			{
				while (true)
				{
					cout << "Please, give coordinates of the " << funnel[j] << " part of Double Funnel Ship: ";
					string data;
					cin >> data;

					if (regex_match(data, pattern))
					{
						temp[2 + 2 * j] = (data.front() - 97);
						if (regex_match(data, pattern10))
							temp[3 + 2 * j] = 9;
						else temp[3 + 2 * j] = data[1] - '0' - 1;
						break;
					}
					else cout << e << endl;
				}
			}

		if (i == 2)
			for (int j = 0; j < 3; j++)
			{
				while (true)
				{
					cout << "Please, give coordinates of the " << funnel[j] << " part of Triple Funnel Ship: ";
					string data;
					cin >> data;

					if (regex_match(data, pattern))
					{
						temp[6 + 2 * j] = (data.front() - 97);
						if (regex_match(data, pattern10))
							temp[7 + 2 * j] = 9;
						else temp[7 + 2 * j] = data[1] - '0' - 1;
						break;
					}
					else cout << e << endl;
				}
			}
	}
	return temp;
}

int PlayerInterface::choosingShip()
{
	while (true)
	{
		string funnel;
		regex pattern("(1|2|3)");
		cout << "Choose a ship, which you want to shoot (1, 2 or 3): ";
		cin >> funnel;
		if (regex_match(funnel, pattern))
			return stoi(funnel);
		else cout << "Wrong number of ship!" << endl;
	}
}

void PlayerInterface::showIncorrectPositions()
{
	cout << "\n\nThe ships overlap, are bent or in touch, or the order is incorrect, try again!\n\n" << endl;
	Sleep(2000);
}

void PlayerInterface::showShootingError()
{
	cout << "\n\nYou cannot shoot there!\n\n" << endl;
}

bool PlayerInterface::anotherShot()
{
	regex patternY("Y|y");
	regex patternN("N|n");
	while (true)
	{
		string choose;
		cout << "Do you want to make another shoot? Y/N: ";

		cin >> choose;
		if (regex_match(choose, patternY) || regex_match(choose, patternN))
		{
			if (regex_match(choose, patternY))
			{
				return true;
				break;
			}
			if (regex_match(choose, patternN))
			{
				return false;
				break;
			}

		}
		else
			cout << "The input is wrong" << endl;
	}

}

int* PlayerInterface::chooseTarget()
{
	int *temp = new int[2]{};
	while (true)
	{
		cout << "Choose coordinates, where you want to shoot: ";
		string data;
		cin >> data;

		regex pattern("([a-j])((10)|(1|2|3|4|5|6|7|8|9))");
		regex pattern10("([a-j])(10)");

		if (regex_match(data, pattern))
		{
			temp[0] = (data.front() - 97);
			if (regex_match(data, pattern10))
				temp[1] = 9;
			else temp[1] = data[1] - '0' - 1;
			return temp;
		}
		else cout << "Wrong coordinates!" << endl;
	}

}

void PlayerInterface::outOfRangeAnnouncement()
{
	cout << "The target is out of range!" << endl;
}

void PlayerInterface::cannotChooseShipAnnouncement()
{
	cout << "You cannot choose this ship!" << endl;
}

void PlayerInterface::shipIsWaitingAnnouncement()
{
	cout << "The ship is waiting!" << endl;
}

void PlayerInterface::missAnnouncement()
{
	cout << "It was a miss!" << endl;
}
void PlayerInterface::hitAnnouncement()
{
	cout << "It was a hit!" << endl;
}

void PlayerInterface::hitAndSunk()
{
	cout << "Hit 'n sunk!" << endl;
}


PlayerInterface::~PlayerInterface()
{
}
