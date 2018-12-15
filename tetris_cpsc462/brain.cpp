#include "brain.h"
#include "clear.h"
#include "PlayerList.h"

#include<iostream>
#include<iomanip>


//namespace Tetris
//{
	// Default constructor
	Brain::Brain()
		: _persistentData(new Persistence::PlayerList),
		_loggerPtr(new Logging::CLogger)
	{
		_logger << "Game has been successfully initialized";
	}



	// Destructor
	Brain::~Brain()
	{
		_logger << "Game shutdown successfully";
	}


	void Brain::SetSpeed() {
		std::cout << "Set difficulty from 1-10 (Low number = slow speed, High number = fast speed)\n"
			">>";
		int s;
		std::cin >> s;

		//40000 is the speed for the slowest setting
		//4000 for the fastest
		gamespeed = 40000 / s;
		difficulty = s;

		std::cout << "\nDifficulty is set to: " << difficulty << endl;
		//system("pause");
		ClearScreen();
	}

	void Brain::DisplaySettingsMenu()
	{
		ClearScreen();
		std::cout << "===========================================================\n"
			" #####   ###### #####  #####  ###  ##    #    ######   #####   \n"
			"#        #        #      #     #   # #   #   #        #        \n"
			" #####   #####    #      #     #   #  #  #  #    ###   #####  \n"
			"      #  #        #      #     #   #   # #   #     #        # \n"
			" #####   ######   #      #    ###  #    ##    #####    #####  \n"
			"===========================================================\n";
		std::cout << "Options\n"
			"1) Difficulty Level (Fall Speed)\tCurrent Level:  " << difficulty << "\n"
			"2) Music Volume\t\t\t\tCurrent Volume: N/A\n"
			"3) Exit Settings\n"
			">> ";
		int c;
		std::cin >> c;
		SetChoice(c);
	}


	void Brain::SetChoice(int c)
	{
		switch (c)
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

		int choice = c;
		DoChoice(choice);
	}

	//call the correct option according to the player choice
	int Brain::DoChoice(int choice)
	{

		switch (choice)
		{
		case 1:
			SetSpeed();
			break;
		case 2:
			std::cout << "Work in Progress\n";
			system("pause");
			ClearScreen();
			break;
		case 3:
			ClearScreen();
			return 0;
		case 0:
			std::cerr << "None of the options were chosen" << std::endl;
			system("pause");
			ClearScreen();
			return -1;
		}
		return 0;

	}
//}