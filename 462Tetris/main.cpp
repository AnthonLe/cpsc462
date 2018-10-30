#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include "brain.h"
#include "game.h"
//#include <conio.h> //for kbhit and getch functions

#include "menu.h"
#include "loginMenu.h"
using namespace std;

int main() 
{

	//create Brain object to change settings
	Brain *brainTest = new Brain();
	
	loginMenu Tester;
	Menu Test;
	int ch = 0;
	int c = 0;
	
	//be shown the login menu
	do
	{
		Tester.DisplayLoginMenu();
		cin >> ch;
		Tester.SetChoice(ch);
	} while (ch == 2);
	
	//complete if able to login correctly
	if (ch == 1) {
		do
		{
			Test.DisplayWelcomeInterface();
			cin >> c;
			//create Game object to begin a new game
			Game *gameTest = new Game();
			Test.SetChoice(*gameTest, *brainTest, c);
		} while (c != 3);
	}

	cout << "BYE\n";

	
	return 0;
}
