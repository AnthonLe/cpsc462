#include "PlayerList.h"
#include "Logger.h"
#include "PersistenceHandler.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <iomanip>

namespace Persistence
{
	PlayerList::PlayerList()
		: _loggerPtr(new Logging::CLogger)     // will replace hard coded implementation class next increment
	{
		_logger << "PlayerList DB being used and has been successfully initialized";
	}



	PlayerList::~PlayerList() noexcept
	{
		_logger << "PlayerList DB shutdown successfully";
	}


	std::vector<std::string> PlayerList::findRoles()
	{
		return{ "Player", "Administrator"};
	}

	void PlayerList::viewPlayerList() 
	{
		std::ifstream infile("PlayerList.txt");
		std::vector<UserCredentials> Users;
		std::vector<UserCredentials> plList;

		string userName, passPhrase, role; //First and last name
		UserCredentials player;
		int count = 0;

		if (infile.is_open())
		{
			while (infile >> player.userName >> player.passPhrase >> player.role)
			{
				Users.push_back(player);
			}

			for (const auto & e : storedUsers)
			{
				std::cout << e.userName << setw(10) << e.passPhrase << setw(10) << e.role << std::endl;
			}

			infile.close();
		}

	}

	void PlayerList::removePlayer()
	{
		std::ifstream infile("PlayerList.txt");
		int count = 0;
		string usr = " ";
		cout << "What username would you like to remove  from playerList?";
		cin >> usr;

		if (infile.is_open())
		{
			std::unique_ptr<Persistence::PersistenceHandler> persistentData;
			persistentData->viewPlayerList();
			cout << endl;

			vector<UserCredentials> User;
			UserCredentials newPlayer;


			for (auto iter = User.begin(); iter != User.end(); ++iter) {
				if (iter->userName == usr) {
					iter = User.erase(iter);
					break;
				}
			}

			//display list of players
			cout << "List of updated usernames: " << endl;
			for (const auto & e : User)
			{
				std::cout << e.userName << setw(10) << e.passPhrase << setw(10) << e.role << std::endl;
			}


		}
		infile.close();
	}

	void PlayerList::addPlayerCredentials(const std::string & name,
		const std::string passPhrase, const std::string role)
	{
		/*struct Users
		{
			std::string               name;
			std::string               passPhrase;
			std::vector<std::string>  roles;
		};*/

		UserCredentials player;
		std::vector<UserCredentials> Users;

		player.userName = name;
		player.passPhrase = passPhrase;
		player.role = role;

		//for (int i = 0; i < storedUsers.size(); i++)
		//{
			//if (storedUsers[i].userName != player.userName)
			//{
				storedUsers.push_back(player);
		//	}
		//}

		/*for (int i = 0; i<storedUsers.size(); i++)

			Users.push_back(storedUsers[i]);*/

		cout << endl;
		
		std::ofstream outFile("PlayerList.txt", ios::app);

		if (outFile.is_open())
		{
			//std::copy(storedUsers.begin(), storedUsers.end(), ostream_iterator<float>(outFile, ", "));
			//outputFile << "GLfloat vector[]={" << copy(vector.begin(), vector.end(), ostream_iterator<float>(cout, ", ")); << "}" << endl;



		//std::ofstream & outFile("PlayerList.txt");
		// the important part
			for (const auto & e : storedUsers)
			{
				outFile << setw(20) <<e.userName << setw(20) << e.passPhrase << setw(20) << e.role << endl;
			}
		}

		outFile.close();

	}

	UserCredentials PlayerList::findCredentialsByName(const std::string & name)
	{
		
		//for (const auto & user : storedUsers) if (user.name == name) return { user.name, user.passPhrase, user.roles };
		
		std::ifstream infile("PlayerList.txt");
		std::vector<UserCredentials> Users;

		string userName, passPhrase, role; //First and last name
		UserCredentials player;

		if (infile.is_open())
		{
			while (infile >> player.userName >> player.passPhrase >> player.role)
			{
				Users.push_back(player);
			}

			for (const auto & user : Users)
			{
				if (user.userName == name)
					return{ user.userName, user.passPhrase, user.role };
			}
		}



		/*if (infile.is_open())
		{
			string line;
			while (getline(infile, line))
			{
				//cout << "test... " << line << "\n";
				//stringstream ss(line);
				UserCredentials player;
				if (getline(infile, line) >> player.userName >> player.passPhrase >> player.role )
				{
					Users.push_back(player);
				}
			}

			for (const auto & user : Users)
			{
				if (user.userName == name)
					return{ user.userName, user.passPhrase, user.role };
			}
		}*/

		infile.close();
		// Name not found, throw something
		std::string message = __func__;
		message += " attempt to find user \"" + name + "\" failed";

		_logger << message;

		throw PersistenceHandler::NoSuchUser(message);
	}

} // namespace Persistence