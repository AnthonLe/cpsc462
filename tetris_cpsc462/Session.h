#ifndef Tetris_Session_h
#define Tetris_Session_h

#include <memory>
#include <string>
#include <vector>


namespace Tetris
{
	// Library Package within the Domain Layer Abstract class
	// The Session abstract class serves as the generalization of all user commands
	struct Session
	{
		// Constructors and assignment operations
		Session() = default;  // default ctor
		Session(const Session &  original) = default;  // copy ctor
		Session(Session && original) = default;  // move ctor

		virtual Session & operator=(const Session &  rhs) = default;  // copy assignment
		virtual Session & operator=(Session && rhs) = default;  // move assignment

																// Operations
		//virtual std::vector<std::string> getCommands() = 0;  // retrieves the list of actions (commands) 

															 // Object Factory returning a specialized object specific to the specified role
		static std::unique_ptr<Session> createSession(const std::string & role);

		// Destructor
		// Pure virtual destructor helps force the class to be abstract, but must still be implemented
		virtual ~Session() noexcept = 0;
	}; // class Session





	   /*****************************************************************************
	   ** Inline implementations
	   ******************************************************************************/
	inline Session::~Session() noexcept
	{}


} // namespace Tetris

#endif // Tetris_Session_h
