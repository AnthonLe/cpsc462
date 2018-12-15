#ifndef Tetris_AdminSession_h
#define Tetris_AdminSession_h

#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include "Session.h"


namespace Tetris
{
	class AdminSession : public Tetris::Session
	{
	public:
		using Session::Session;  // inherit constructors

								 // Operations
		std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands) 


		void AdminSession::displayAdminMenu()
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

		}


														  // Destructor
														  // Pure virtual destructor helps force the class to be abstract, but must still be implemented
		~AdminSession() noexcept override;
	}; // class AdministratorSession





	   /*****************************************************************************
	   ** Inline implementations
	   ******************************************************************************/
	inline AdminSession::~AdminSession() noexcept
	{}


	inline std::vector<std::string> AdminSession::getCommands()
	{
		return{ "Showdown", "Reset Account", "Help" };
	}

} // namespace Tetris

#endif // Tetris_AdminSession_h
