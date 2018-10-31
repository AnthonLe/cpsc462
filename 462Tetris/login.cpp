#include <iostream>
#include <fstream>
#include <string>
#include "loginMenu.h"
#include "clear.h"
#include "game.h"
#include "brain.h"

using namespace std;


void loginMenu::sendNAME()
{
	cout << "Enter your desired username: ";
	cin >> userName;
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
};

void loginMenu::sendPWORD()
{
	cout << "Enter your desired password: ";
	cin >> pword;
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
};

void loginMenu::DisplayLoginMenu()
{
	ClearScreen();
	cout << "======================================================\n"
		" #####  ###### #####  ######    ###    #####\n"
		"   #    #        #    #     #    #    #     \n"
		"   #    #####    #    ######     #     #####\n"
		"   #    #        #    #   #      #          #\n"
		"   #    ######   #    #     #   ###    #####\n"


		"======================================================\n";
	
	cout << "Welcome to the login menu...\n"
		"1) Login\n"
		"2) Register\n"
		"3) Exit Game\n"
		">>";

}

void loginMenu::login(ifstream & readFile)
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
		string playerList[20];
		for (int i = 0; i < 20; i++)
		{
			readFile >> playerList[i];
		}

		cout << "scanning for username..." << endl;
		
		//
		for (int j = 0; j < 20; j += 2)
		{
			//checking if user is admin
			if (username == playerList[j] && (username == admins[0] || username == admins[1] || username == admins[2]))

			{
				ClearScreen();
				cout << "\nUsername found, checking password" << endl;
				
				if (password == playerList[j + 1])
				{
					cout << "\nWelcome Admin " << username << "!" << endl;
					//pass++;
					check++;
					break;
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
					//pass++;
					break;
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
		User.login(readFile);
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

}


/*int main()
{
	ifstream readFile("PlayerList.txt");
	ofstream writeFile("PlayerList.txt", ios::app);
	Player playerInfo;
	int choice = 0;

	do
	{
		choice = playerInfo.startMenu();

		switch (choice)
		{
		case 1:
			playerInfo.login(readFile);
			break;
		case 2:
			playerInfo.registerPlayer(writeFile);
			break;
		case 3:
			cout << "Goodbye!" << endl;
			break;
		default:
			cout << "Invalid selections" << endl;
			break;
		}
	} while (choice == 2);
	
	return 0;

}*/
