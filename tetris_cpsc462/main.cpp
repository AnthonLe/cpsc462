#include <exception>
#include <iostream>
#include <memory>
#include <new>
#include <iostream>
#include <locale>

#include "SimpleUI.h"
#include "UIHandler.h"


int main( /*int argc, char argv[] */)
{
	try
	{
		std::cout << "\Tetris Game system initializing ...\n\n";

		// Smart pointer (for proper, exception safe memory management) to interface set to new instance of a specific implementation of
		// the interface. We'll replace the hard coded specific instance with a call to a object factory in the next increment.
		std::unique_ptr<UI::UIHandler> userInterface(new UI::SimpleUI); // Hard coded to UI::SimpleUI for now

		std::cout << "\nInitialization completed successfully\n";

		char response;
		do
		{
			std::cout << "Ready to transition into Operational State? (Y/N/Q) ";
			std::cin >> response;
			response = std::toupper(response, std::locale());
		} while (response != 'Y' && response != 'Q');

		if (response == 'Y') userInterface->launch();


		std::cout << "\nGame complete, initiating shutdown\n";
	}

	catch (const std::bad_alloc & ex)
	{
		std::cerr << "Fatal:  Uncaught memory allocation exception\n\n"
			<< ex.what() << '\n';
	}

	catch (const std::exception & ex)
	{
		std::cerr << "Fatal:  Uncaught standard exception\n"
			<< ex.what() << '\n';
	}

	catch (...)
	{
		std::cerr << "Fatal:  Uncaught (unknown type) exception\n";
	}
}





/*#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <chrono>
#include "brain.h"
#include "game.h"

#include "menu.h"
#include "loginMenu.h"
#include "admin.h"
#include "Logger.h"

using namespace std;

int main(int argc, char *argv[])
{

	//create Brain object to change settings
	Brain *brainTest = new Brain();
	
	loginMenu Tester;
	Menu playerMenu;
	Admin admMenu;

	int pass1 = 0;
	int pass2 = 0;
	
	int ch = 0;
	int c = 0;
	int ad = 0;

	CLogger::GetLogger()->Log("UI being used and has been successfully initialized!");
	
	//be shown the login menu
	do
	{
		Tester.DisplayLoginMenu();
		cin >> ch;
		Tester.SetChoice(ch);

		
		//to determine if user or admin
		pass1 = Tester.getUserPass();
		pass2 = Tester.getAdminPass();

	} while (ch == 2 || (pass1 == 0 && pass2 == 0));
	
	//redirects to player menu
	if (ch == 1 && pass1 == 1) {
		do
		{
			playerMenu.DisplayWelcomeInterface();
			cin >> c;
			CLogger::GetLogger()->Log("Login Successful for Player!");

			//create Game object to begin a new game
			Game *gameTest = new Game();
			playerMenu.SetChoice(*gameTest, *brainTest, c);
		} while (c != 3);
	}

	//redirects to admin menu
	else if (ch == 1 && pass2 == 1)
	{
		do
		{
			admMenu.displayAdminMenu();
			cin >> ad;
			CLogger::GetLogger()->Log("Login Successful for Admin!");

			admMenu.SetChoice(*brainTest, ad);
		} while (ad != 4);
	}

	else {
		CLogger::GetLogger()->Log("Looks like something went wrong with logging in!");
	}
	
	cout << "BYE\n";
	CLogger::GetLogger()->Log("System is shut down succesfully");

	return 0;
}*/


