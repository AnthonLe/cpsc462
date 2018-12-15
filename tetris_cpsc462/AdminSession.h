#ifndef Tetris_AdminSession_h
#define Tetris_AdminSession_h

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Session.h"
#include "PlayerList.h"
#include "Logger.h"
#include "PersistenceHandler.h"


namespace Tetris
{
	class AdminSession :public Tetris::Session
	{
	public:
		using Session::Session;  // inherit constructors
		int choice;

		std::unique_ptr<Persistence::PersistenceHandler> persistentData;

		//_persistentData(new Persistence::PlayerList);

		std::vector<std::string> plList;
		//void displayAdminMenu();
		//void SetChoice(Brain &, int);
		void viewPlayerList()
		{
			ifstream readFile("PlayerList.txt");
			int count = 0;
			if (readFile.is_open())
			{
				//display list of players
				cout << "List of usernames: " << endl;

				//std::unique_ptr<Persistence::Playerlist> persistentData;

				//std::unique_ptr<Persistence::Playerlist> persistentData;

				//Playerlist player;

				persistentData->viewPlayerList();

				readFile.close();
			}
		}

		void removePlayer() 
		{
			ifstream readFile("PlayerList.txt");
			int count = 0;
			if (readFile.is_open())
			{

				persistentData->removePlayer();

				readFile.close();
			}
		}


														  // Destructor
														  // Pure virtual destructor helps force the class to be abstract, but must still be implemented
		~AdminSession() noexcept override;

	//private:
		//int DoChoice(Brain &, int);
	}; // class AdministratorSession





	   /*****************************************************************************
	   ** Inline implementations
	   ******************************************************************************/
	inline AdminSession::~AdminSession() noexcept
	{}


} // namespace Tetris

#endif // Tetris_AdminSession_h
