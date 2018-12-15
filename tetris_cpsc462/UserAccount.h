#ifndef Domain_AccountManagement_UserAccount_hpp
#define Domain_AccountManagement_UserAccount_hpp

#include <memory>  // std::unique_ptr
#include <string>

#include "Logger.h"
#include "AccountManagementHandler.h"
#include "PersistenceHandler.h"
//#include "Domain/AccountManagement/AccountManagementHandler.hpp"
//#include "TechicalServices/Logging/LoggerHandler.hpp"
//#include "TechicalServices/Persistence/PersistenceHandler.hpp"



namespace AccountManagement
{
	class UserAccount : public AccountManagement::AccountManagementHandler
	{
	public:
		using AccountManagementHandler::AccountManagementHandler;  // inherit constructors
		UserAccount();


		// Operations
		bool isAuthentcated(const UserCredentials & credentials) override;


		// Destructor
		~UserAccount() noexcept override;


	private:
		// These smart pointers hold pointers to lower architectural layer's interfaces
		std::unique_ptr<Persistence::PersistenceHandler>    _persistentData;
		std::unique_ptr<Logging::CLogger>             _loggerPtr;


		// convenience reference object enabling standard insertion syntax
		// This line must be physically after the definition of _loggerPtr
		Logging::CLogger                          & _logger = *_loggerPtr;
	};
} // namespace AccountManagement



#endif // Domain_AccountManagement_UserAccount_hpp

