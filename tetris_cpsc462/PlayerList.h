#ifndef PlayerList_h
#define PlayerList_h

#include <memory>

#include "Logger.h"
#include "PersistenceHandler.h"


namespace Persistence
{
	class PlayerList : public PersistenceHandler
	{
	public:
		using PersistenceHandler::PersistenceHandler;    // inherit constructors
		PlayerList();

		std::vector<UserCredentials> storedUsers = 
		{
			// Username    PassPhase         Authorized roles
			{ "Sarah ",     " twice ", " Administrator"  },
			{ "Anthony ", " cpsc462 ", " Administrator"  },
			{ "Dominick ",  " done ", " Administrator"  }
		};

		// Operations
		std::vector<std::string> findRoles()                                       override;  // Returns list of all legal roles
		UserCredentials          findCredentialsByName(const std::string & name) override;  // Returns credentials for specified user, throws NoSuchUser if user not found
		void	 addPlayerCredentials(const std::string & name, const std::string passPhrase,
			const std::string role) override;

		void viewPlayerList();
		void removePlayer();


		~PlayerList() noexcept override;

	private:
		std::unique_ptr<Logging::CLogger>             _loggerPtr;

		// convenience reference object enabling standard insertion syntax
		// This line must be physically after the definition of _loggerPtr
		Logging::CLogger                           & _logger = *_loggerPtr;

	}; // class PlayerList
}  // namespace Persistence

#endif // Persistence_PlayerList_h


