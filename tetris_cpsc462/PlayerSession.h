#ifndef Tetris_PlayerSession_h
#define Tetris_PlayerSession_h

#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include "Session.h"


namespace Tetris
{
	class PlayerSession : public Tetris::Session
	{
	public:
		using Session::Session;  // inherit constructors

								 // Operations
		//std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands) 


														  // Destructor
														  // Pure virtual destructor helps force the class to be abstract, but must still be implemented
		~PlayerSession() noexcept override;
	}; // class PlayerSession





	   /*****************************************************************************
	   ** Inline implementations
	   ******************************************************************************/
	inline PlayerSession::~PlayerSession() noexcept
	{}


} // namespace Tetris

#endif // Tetris_PlayerSession_h

