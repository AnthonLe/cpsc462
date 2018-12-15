#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <new>
#include <string>
#include <vector>

/*#include "Domain/AccountManagement/UserAccounts.hpp"  
#include "Domain/Library/Books.hpp"                  
#include "Domain/Library/Session.hpp"
#include "TechicalServices/Logging/LoggerHandler.hpp"
#include "SimpleLogger.h"  
#include "SimpleDB.h"  
#include "SimpleUI.h"*/
#include "Logger.h"
#include "PlayerList.h"
#include "UserAccount.h"
#include "SimpleUI.h"
#include "Session.h"
#include "game.h"
#include "brain.h"

namespace UI
{
	// Default constructor
	SimpleUI::SimpleUI()
		: _persistentData(new Persistence::PlayerList),   
		_loggerPtr(new Logging::CLogger),    
		_accounts(new AccountManagement::UserAccount),   
		_game(new Tetris::Game),
		_brains(new Tetris::Brain)
		//_boards(new Tetris::Board)
	{
		_logger << "Simple UI being used and has been successfully initialized";
	}


	// Destructor
	SimpleUI::~SimpleUI() noexcept
	{
		_logger << "Simple UI shutdown successfully";
	}


	// Operations
	void SimpleUI::launch()
	{
		// 1) Fetch Role legal value list

		std::vector<std::string> roleLegalValues = _persistentData->findRoles();
		std::string selectedRole;
		int choice = 0;
		//std::ofstream outFile("PlayerList.txt");

		// 2) Present login screen to user and get username, password, and valid role
		do
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "======================================================\n"
				" #####  ###### #####  ######    ###    #####\n"
				"   #    #        #    #     #    #    #     \n"
				"   #    #####    #    ######     #     #####\n"
				"   #    #        #    #   #      #          #\n"
				"   #    ######   #    #     #   ###    #####\n"


				"======================================================\n";

			std::cout << "Welcome to the login menu\n"
				"1) Login\n"
				"2) Register\n"
				"3) Exit Game\n"
				">>";

			std::cin >> choice;
			std::string userName;
			std::string passPhrase;
			std::string role;

			if (choice == 1)
			{
				cout << "Enter userName: ";
				std::cin >> userName;
				cout << endl;

				cout << "Enter Pass phrase: ";
				std::cin >> passPhrase;
				cout << endl;

				unsigned menuSelection;
				
				do
				{
					for (unsigned i = 0; i != roleLegalValues.size(); ++i)   std::cout << std::setw(2) << i << " - " << roleLegalValues[i] << '\n';
					std::cout << "  role (0-" << roleLegalValues.size() - 1 << "): ";
					std::cin >> menuSelection;
				} while (menuSelection >= roleLegalValues.size());

				selectedRole = roleLegalValues[menuSelection];


				// 3) Validate user is authorized for this role
				if (_accounts->isAuthentcated({ userName, passPhrase,{ selectedRole } }))
				{
					_logger << "Login Successful for \"" + userName + "\" as role \"" + selectedRole + "\"";
					break;
				}

				std::cout << "** Login failed\n";
				_logger << "Login failure for \"" + userName + "\" as role \"" + selectedRole + "\"";
			} 

			else if (choice == 2)
			{
				cout << "Enter userName: ";
				std::cin >> userName;
				cout << endl;

				cout << "Enter Pass phrase: ";
				std::cin >> passPhrase;
				cout << endl;

				cout << "Are you a Player or Administrator? (Enter One) ";
				std::cin >> role;
				cout << endl;

				_persistentData->addPlayerCredentials(userName, passPhrase, role);
			} 

			else if (choice == 3)
			{
				cout << "BYE\n";
				//CLogger::GetLogger()->Log("System is shut down succesfully");
				break;
			}
		} while (true);


		// 4) Fetch functionality options for this role
		std::unique_ptr<Tetris::Session> sessionControl = Tetris::Session::createSession(selectedRole);

		std::vector<std::string> commands = sessionControl->getCommands();
		unsigned menuSelection;
		int chn = 0;
		do
		{
			if (selectedRole == "Player")
			{
				std::cout << "======================================================\n"
					"           #########  ###### #######  #     # \n"
					"           #   #   #  #      #     #  #     # \n"
					"           #   #   #  #####  #     #  #     # \n"
					"           #   #   #  #      #     #  #     # \n"
					"           #   #   #  ###### #     #  ####### \n"


					"======================================================\n";

				std::cout << "Menu Options\n"
					"1) Start New Game\n"
					"2) Change Settings\n"
					"3) Exit Game\n"
					">> ";

				std::cin >> chn;

				if (chn == 1)
				{
					//Game *gameTest = new Game();
					//playerMenu.SetChoice(*gameTest, *brainTest, c);
					//Brain *brainTest = new Brain();
					//Tetris::Brain *brainTest = new Tetris::Brain;
					std::unique_ptr<Tetris::Game> gameTest;
					std::unique_ptr<Tetris::Brain> brainTest;
					//std::unique_ptr<Tetris::Board> boardTest;

					//playerMenu.SetChoice(*gameTest, *brainTest, chn);
					_game->StartNewGame(*gameTest, *brainTest);
					//_boards->CreateBoard(* gameTest);
					//_game->UpdateGame(*gameTest, *brainTest, *boardTest);
				}

				else if (chn == 2)
				{
					_brains->DisplaySettingsMenu();
				}

				else if (chn == 3)
				{
					cout << "BYE\n";
					//CLogger::GetLogger()->Log("System is shut down succesfully");
					break;
				}

				else
				{
					cout << "invalid command" << endl;
				}

			}

			else if (selectedRole == "Administrator")
			{
				std::cout << "======================================================\n"
					"           #########  ###### #######  #     # \n"
					"           #   #   #  #      #     #  #     # \n"
					"           #   #   #  #####  #     #  #     # \n"
					"           #   #   #  #      #     #  #     # \n"
					"           #   #   #  ###### #     #  ####### \n"


					"======================================================\n";

				std::cout << "Menu Options for Admin\n"
					"1) View PlayerList\n"
					"2) Remove Players\n"
					"3) Change Settings\n"
					"4) Exit Game\n"
					">> ";

				std::cin >> chn;

				if (chn == 1)
				{
					cout << endl;
				}

				else if (chn == 2)
				{
					cout << endl;
				}

				else if (chn == 3) 
				{
					cout << endl;
				}
				
				else if (chn == 4)
				{
					cout << "BYE\n";
					//CLogger::GetLogger()->Log("System is shut down succesfully");
					break;
				}

				else 
				{
					cout << "invalid command" << endl;
				}
			}


			for (unsigned i = 0; i != commands.size(); ++i)   std::cout << std::setw(2) << i << " - " << commands[i] << '\n';
			std::cout << "  role (0-" << commands.size() - 1 << "): ";
			std::cin >> menuSelection;
		} while (menuSelection >= roleLegalValues.size());

		//std::string selectedCommand = commands[menuSelection];
		//_logger << "Selected command \"" + selectedCommand + "\" chosen";
	}
}

/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "loginMenu.h"
#include "clear.h"
#include "game.h"
#include "brain.h"

using namespace std;

int loginMenu::getAdminPass()
{
	return adminPass;
}

int loginMenu::getUserPass()
{
	return userPass;
}

void loginMenu::setAdminPass(int & adminPass)
{
	this->adminPass = adminPass;
}

void loginMenu::setUserPass(int & userPass)
{
	this->userPass = userPass;
}

void loginMenu::sendNAME()
{
	cout << "Enter your desired username: ";
	cin >> userName;
};

void loginMenu::sendPWORD()
{
	cout << "Enter your desired password: ";
	cin >> pword;
};

void loginMenu::DisplayLoginMenu()
{

	cout << "======================================================\n"
		" #####  ###### #####  ######    ###    #####\n"
		"   #    #        #    #     #    #    #     \n"
		"   #    #####    #    ######     #     #####\n"
		"   #    #        #    #   #      #          #\n"
		"   #    ######   #    #     #   ###    #####\n"


		"======================================================\n";

	cout << "Welcome to the login menu\n"
		"1) Login\n"
		"2) Register\n"
		"3) Exit Game\n"
		">>";

}

void loginMenu::login(ifstream & readFile, int & userPass, int & adminPass)
{
	string username;
	string password;

	//string array of the admins
	string admins[3] = { "Sarah", "Anthony", "Dominick" };

	int check = 0;

	if (readFile.is_open())
	{
		cout << "Enter userName: ";
		cin >> username;
		cout << endl;

		cout << "Enter Password: ";
		cin >> password;
		cout << endl;

		//storing all the usernames and password into a string array

		vector<string> playerList;
		string read = "";

		while (readFile >> read)
		{
			playerList.push_back(read);
		}

		cout << "scanning for username..." << endl;

		//
		for (int j = 0; j < playerList.size(); j += 2)
		{
			//checking if user is admin
			if (username == playerList[j] && (username == admins[0] || username == admins[1] || username == admins[2]))

			{
				ClearScreen();
				cout << "\nUsername found, checking password" << endl;

				if (password == playerList[j + 1])
				{
					cout << "\nWelcome Admin " << username << "!" << endl;
					check++;
					adminPass++;
					setAdminPass(adminPass);
					break;
				}

				else
				{
					cout << "Invalid password " << endl;

				}
			}

			//checking if player's username and password is valid
			else if (username == playerList[j] && (username != admins[0] || username != admins[1] || username != admins[2]))
			{
				ClearScreen();
				cout << "\nUsername found, checking password" << endl;

				if (password == playerList[j + 1])
				{
					cout << "\nWelcome User " << username << "!" << endl;
					check++;
					userPass++;
					setUserPass(userPass);
					break;
				}

				else
				{
					cout << "Invalid password " << endl;

				}
			}

		}

		//checking if the above if statements in the for loop were execureted
		//if not then return not valid username
		if (check == 0)
		{
			cout << "\nInvalid username or password." << endl;
		}

		readFile.close();
	}
};

void loginMenu::registerPlayer(ofstream & writeFile)
{
	loginMenu playerInfo;

	playerInfo.sendNAME();
	cout << endl;
	playerInfo.sendPWORD();
	cout << endl;

	//adding username and password to PlayerList txt file
	if (writeFile.is_open())
	{
		writeFile << playerInfo.userName << endl;
		writeFile << playerInfo.pword << endl;
		writeFile.close();
	}

	else
	{
		cout << "Unable to open file";
	}
};

//function checks to see if a valid choice was made before setting it
void loginMenu::SetChoice(int ch)
{
	switch (ch)
	{
	case 1:
	case 2:
	case 3:
		break;
		//if any number other than 1,2,3 is chosen, reset choice to 0
	default:
		ch = 0;
		break;
	}

	choice = ch;
	DoChoice(choice);
}

//call the correct option according to the player choice
int loginMenu::DoChoice(int choice)
{
	ifstream readFile("PlayerList.txt");
	ofstream writeFile("PlayerList.txt", ios::app);
	loginMenu User;

	switch (choice)
	{
	case 1:
		User.login(readFile, userPass, adminPass);
		break;
	case 2:
		User.registerPlayer(writeFile);
		break;
	case 3:
		return 0;
	case 0:
		cerr << "None of the options were chosen" << std::endl;
		system("pause");
		return -1;
	}
	return 0;
}*/






