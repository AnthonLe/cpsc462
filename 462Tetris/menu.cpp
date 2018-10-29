#include <iostream>
#include <iostream>
#include "menu.h"
#include "game.h"
using namespace std;

//clear the console/terminal by creating a lot of newlines
void Menu::clear()
{
	int n;
	for (n = 0; n < 10; n++)
		printf("\n\n\n\n\n\n\n\n\n\n");
}

void Menu :: DisplayWelcomeInterface()
{
	cout << "======================================================\n"
		" #####  ###### #####  ######    ###    #####\n"
		"   #    #        #    #     #    #    #     \n"
		"   #    #####    #    ######     #     #####\n"
		"   #    #        #    #   #      #          #\n"
		"   #    ######   #    #     #   ###    #####\n"


		"======================================================\n";
	cout << "Menu Options\n"
		"1) Start New Game\n"
		"2) Change Settings\n"
		"3) Exit Game\n"
		">> ";
}

void Menu::DisplaySettingsMenu()
{
	clear();
	cout << "===========================================================\n"
		" #####   ###### #####  #####  ###  ##    #    ######    #####   \n"
		"#        #        #      #     #   # #   #   #         #        \n"
		" #####   #####    #      #     #   #  #  #  #     ###   #####  \n"
		"      #  #        #      #     #   #   # #   #      #        # \n"
		" #####   ######   #      #    ###  #    ##    #####     #####  \n"


		"===========================================================\n";

}

int Menu::DisplayGameOver()
{
	clear();
	cout << "You suck\n";

	return 0;
}

//function checks to see if a valid choice was made before setting it
void Menu::SetChoice(int c)
{
	switch(c)
	{
		case 1:
		case 2:
		case 3:
			break;
			//if any number other than 1,2,3 is chosen, reset choice to 0
		default:
			c = 0;
			break;
	}

	choice = c;
	DoChoice(choice);
}

//call the correct option according to the player choice
int Menu::DoChoice(int choice)
{
	//create Game object to begin a new game
	Game *gameTest = new Game();
	switch (choice)
	{
	case 1:
		gameTest->StartNewGame(*gameTest);
		break;
	case 2:
		DisplaySettingsMenu();
		break;
	case 3:
		return 0;
	case 0:
		std::cerr << "None of the options were chosen" << std::endl;
		return -1;
	}
	return 0;


}