#include <memory>
#include <stdexcept>
#include <string>
#include <vector>


/*#include "Domain/Library/AdministratorSession.hpp"
#include "Domain/Library/ManagementSession.hpp"
#include "Domain/Library/Session.hpp"*/

#include "Session.h"
#include "PlayerSession.h"
#include "AdminSession.h"


namespace Tetris
{
	// returns a specialized object specific to the specified role
	std::unique_ptr<Session>  Session::createSession(const std::string & role)
	{
		// Just as a smart defensive strategy, one should verify this role is one of the roles in the DB's legal value list.  I'll come
		// back to that

		if (role == "Player")    return std::make_unique<Tetris::PlayerSession>();
		else if (role == "Administrator")    return std::make_unique<Tetris::AdminSession>();
		else
		{
			throw std::logic_error("Invalid role requested in function " + std::string(__func__)); 
		}
	}

} // namespace Tetris