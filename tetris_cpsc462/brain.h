#ifndef Tetris_Brain_h
#define Tetris_Brain_h

#include <iostream>

#include "game.h"
#include "SimpleUI.h"
#include "board.h"
#include "block.h"
#include "brain.h"
#include "PlayerList.h"

namespace Tetris
{
	class Brain
	{
	public:

		size_t gamespeed = 20000;
		//change the gamespeed
		void SetSpeed();

		void DisplaySettingsMenu();
		void SetChoice(int c);
		int DoChoice(int c);

		Brain();

		// Destructor
		~Brain() ;

	private:
		//default difficulty is 5, ranges from 1-10
		int difficulty = gamespeed / 4000;

		std::unique_ptr<Persistence::PersistenceHandler>    _persistentData;
		std::unique_ptr<Logging::CLogger>             _loggerPtr;


		// convenience reference object enabling standard insertion syntax
		// This line must be physically after the definition of _loggerPtr
		Logging::CLogger                            & _logger = *_loggerPtr;

	};
}  // namespace Tetris

#endif // Tetris_Brain_h
