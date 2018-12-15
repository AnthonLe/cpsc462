#include <algorithm>  // std::any_of()

#include "UserAccount.h"
#include "Logger.h"
#include "PlayerList.h"
//#include "TechicalServices/Logging/SimpleLogger.hpp"
//#include "TechicalServices/Persistence/SimpleDB.hpp"



namespace AccountManagement
{
	// Default constructor
	UserAccount::UserAccount()
		: _persistentData(new Persistence::PlayerList),   // will replace hard coded implementation class next increment
		_loggerPtr(new Logging::CLogger)     // will replace hard coded implementation class next increment
	{
		//CLogger::GetLogger()->Log("UserAccounts being used and has been successfully initialized!");
		_logger << "UserAccounts being used and has been successfully initialized";
	}


	// Destructor
	UserAccount::~UserAccount() noexcept
	{
		//CLogger::GetLogger()->Log("UserAccounts shutdown successfully!");
		_logger << "UserAccounts shutdown successfully";
	}

	//ifstream  readFile("PlayerList.txt");

	// Operations
	bool UserAccount::isAuthentcated(const UserCredentials & credentials)
	{
		try
		{
			UserCredentials credentialsFromDB = _persistentData->findCredentialsByName(credentials.userName);

			// std::set_intersection might be a better choice, but here I'm assuming there will be one and only one role in the passed-in
			// credentials I just need to varify the requested role is in the set of authorized roles.  Someday, if a user can sign in
			// with many roles combined, I may have to revisit this approach.  But for now, this is good enough.
			if (credentials.userName == credentialsFromDB.userName
				&& credentials.passPhrase == credentialsFromDB.passPhrase
				&& credentials.role == credentialsFromDB.role
				) return true;
		}
		catch (const Persistence::PersistenceHandler::NoSuchUser &) {}  // Catch and ignore this anticipated condition

		return false;
	}

} // namespace AccountManagement