#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include "brain.h"
#include "game.h"
//#include <conio.h> //for kbhit and getch functions

#include "menu.h"
using namespace std;

int main() {

	//create Brain object to change settings
	Brain *brainTest = new Brain();


	Menu Test;
	int c = 0;
	do {
		Test.DisplayWelcomeInterface();
		cin >> c;
		//create Game object to begin a new game
		Game *gameTest = new Game();
		Test.SetChoice(*gameTest, *brainTest, c);
	} while (c != 3);

	cout << "BYE\n";

	
	return 0;
}