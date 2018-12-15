#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <iomanip>
#include "brain.h"
#include "game.h"
#include "score.h"

#include "menu.h"
#include "loginMenu.h"
#include "admin.h"
#include "SimpleLogger.h"

int main() 
{

	//create Brain object to change settings
	Brain *brainTest = new Brain();
	Score *scoreTest = new Score();
	
	loginMenu Tester;
	Menu playerMenu;
	Admin admMenu;

	string usern = Tester.userName;

	int pass1 = 0;
	int pass2 = 0;
	
	int ch = 0;
	int c = 0;
	int ad = 0;


	// Create Logger System and output to txt file
	Logger::SimpleLogger myLog("1.0.4.2", "LoggerSystem.txt");

	myLog << Logger::SimpleLogger::e_logType::LOG_UISUCCESS << "UI being used and has been successfully initialized!";

	//be shown the login menu
	do
	{
		Tester.DisplayLoginMenu();
		cin >> ch;
		Tester.SetChoice(ch);

		
		//to determine if user or admin
		pass1 = Tester.getUserPass();
		pass2 = Tester.getAdminPass();

	} while (pass1 == 0 && pass2 == 0);
	
	//redirects to player menu
	if (ch == 1 && pass1 == 1) {
		do
		{
			playerMenu.DisplayWelcomeInterface();
			cin >> c;

			//log when player was able to log in
			myLog << Logger::SimpleLogger::e_logType::LOG_LOGINSUCCESS << "Login Successful for Player!";

			//create Game object to begin a new game
			Game *gameTest = new Game();
			playerMenu.SetChoice(*gameTest, *brainTest, *scoreTest, c);
		} while (c != 4);
	}

	//redirects to admin menu
	else if (ch == 1 && pass2 == 1)
	{
		do
		{
			admMenu.displayAdminMenu();
			cin >> ad;

			//log when admin was able to login
			myLog << Logger::SimpleLogger::e_logType::LOG_LOGINSUCCESS << "Login Successful for Admin!";

			admMenu.SetChoice(*brainTest, ad);
		} while (ad != 4);
	}

	else
	{
		//if no correct options were choosen at the menu then error message
		myLog << Logger::SimpleLogger::e_logType::LOG_ERROR << "Looks like something went wrong with logging in!";
	}

	cout << "BYE\n";

	//log when system is shutting down
	myLog << Logger::SimpleLogger::e_logType::LOG_DOWNSUCCESS << "Logger shutdown successfully!";
	
	return 0;
}

