#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

#include "Computer.h"
#include "GameLogic.h"
#include "Human.h"
#include "Player.h"
#include "Ship.h"
#include "Square.h"

using std::fstream;
using std::ifstream;
using std::ios;

using namespace std;

int main(int argc, char *argv[])
{
	srand(time(0));
	try
	{
		if (static_cast<string>(argv[1]) == "--help")
		{
			cout << "\n\nHELP MENU:\nThis is the Battle Ship game.\n\n"
				<< "The basic input of the program is <program_name> <--command> <value>\n"

				<< "If you would like to play versus computer:\n"
				<< "<program_name> <--normal> <rounds> <strategy>\n\n"

				<< "If you would like to see a simulation of play:\n"
				<< "<program_name> <--simulation> <rounds> <strategy_of_first> <strategy_of_second>\n\n"

				<< "Where rounds is number of rounds, not more than 20 and strategies can be 1 - greedy or 2 - random.\n\n"
				<< "Symbols such as <>, (), [], {} are not allowed.\n\n"

				<< "If you would like to load game:\n"
				<< "<program_name> <--load>\n\n";
			return 0;
		}

		if (static_cast<string>(argv[1]) == "--normal")
		{
			if (argc != 4) throw "Incorrect syntax. Please, see --help.";
			if (stoi(argv[2]) <= 0 || stoi(argv[2]) > 20) throw "Incorrect number of rounds. Please, see --help.";

			if (static_cast<string>(argv[3]) != "greedy" && static_cast<string>(argv[3]) != "random") throw "Incorrect strategy. Please, see --help.";

			GameLogic* newGame = new GameLogic(stoi(argv[2]), argv[3], 1);
			newGame->placingShips();
			newGame->play();

			return 0;
		}

		if (static_cast<string>(argv[1]) == "--simulation")
		{
			if (argc != 5) throw "Incorrect syntax. Please, see --help.";
			if (stoi(argv[2]) <= 0 || stoi(argv[2]) > 20) throw "Incorrect number of rounds. Please, see --help.";

			if ((static_cast<string>(argv[3]) != "greedy" && static_cast<string>(argv[3]) != "random") && (static_cast<string>(argv[4]) != "greedy" && static_cast<string>(argv[4]) != "random"))
				throw "Incorrect strategy. Please, see --help.";

			GameLogic *newGame = new GameLogic(stoi(argv[2]), argv[3], argv[4], 1);

			newGame->simulation();
			return 0;
		}

		if (static_cast<string>(argv[1]) == "--load")
		{
			if (argc != 2) throw "Incorrect syntax. Please, see --help.";
			
			ifstream f("SaveFile.txt");

			if (f)
			{
				string line;
				string strategy;

				getline(f, line);
				int roundCounter = stoi(line);
				getline(f, line);

				int rounds = stoi(line);
				getline(f, line);

				int s = line.front();
				if (s == 1) strategy = "greedy";
				if (s == 2) strategy == "random";
				GameLogic newGame(rounds, strategy, roundCounter);

				newGame.load("SaveFile.txt");
				return 0;
			}
			else throw "Error while opening the file!";
		}
		throw "Incorrect syntax. Please, see --help.";
	}

	catch (const char* e)
	{
		cerr << endl << e << endl;
		cin.ignore();
		return 1;
	}

	catch (...)
	{
		cerr << "\nUnknown error!" << endl;
		cin.ignore();

		return 2;
	}
}