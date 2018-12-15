#ifndef UI_SimpleUI_h
#define UI_SimpleUI_h


#include <memory>  // std::unique_ptr


/*#include "Domain/Library/MaintainBooksHandler.hpp"
#include "Domain/AccountManagement/AccountManagementHandler.hpp"
#include "TechicalServices/Logging/LoggerHandler.hpp"
#include "TechicalServices/Persistence/PersistenceHandler.hpp"
#include "UI/UserInterfaceHandler.hpp"*/

#include "Logger.h"
#include "UIHandler.h"
#include "PersistenceHandler.h"
#include "AccountManagementHandler.h"
#include "game.h"
#include "brain.h"

//class Game;

namespace UI
{
	/*****************************************************************************
	** Simple UI definition
	**   Simple UI is a console application meant only as a driver to the Domain Layer application. This UI will someday be replaced
	**   by a more sophisticated, user friendly implementation
	******************************************************************************/
	class SimpleUI : public UI::UIHandler
	{
	public:
		using UIHandler::UIHandler;  // inherit constructors
		SimpleUI();

		// Operations
		void launch() override;


		// Destructor
		~SimpleUI() noexcept override;


	private:
		// These smart pointers hold pointers to lower architectural layer's interfaces
		std::unique_ptr<Persistence::PersistenceHandler>    _persistentData;
		std::unique_ptr<Logging::CLogger>             _loggerPtr;
		std::unique_ptr<AccountManagement::AccountManagementHandler>  _accounts;
		std::unique_ptr<Tetris::Game>  _game;
		std::unique_ptr<Tetris::Brain>  _brains;
		//std::unique_ptr<Tetris::Board>  _boards;


		// convenience reference object enabling standard insertion syntax
		// This line must be physically after the definition of _loggerPtr
		Logging::CLogger                            & _logger = *_loggerPtr;
	};
} // namespace UI

#endif // UI_SimpleUI_h
