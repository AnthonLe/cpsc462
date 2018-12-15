#ifndef AccountManagement_AccountManagementHandler_h
#define AccountManagement_AccountManagementHandler_h

#include <string>

#include "PersistenceHandler.h"


namespace AccountManagement
{
	// Import the User Credentials type from the lower layer and publish it as your own
	using Persistence::UserCredentials;

	// Account Management Package within the Domain Layer Abstract class
	struct AccountManagementHandler
	{
		// Constructors and assignment operations
		AccountManagementHandler() = default;    // default ctor
		AccountManagementHandler(const AccountManagementHandler &  original) = default;    // copy ctor
		AccountManagementHandler(AccountManagementHandler && original) = default;    // move ctor

		virtual AccountManagementHandler & operator=(const AccountManagementHandler &  rhs) = default;    // copy assignment
		virtual AccountManagementHandler & operator=(AccountManagementHandler && rhs) = default;    // move assignment


																									// Operations
		virtual bool isAuthentcated(const UserCredentials & credentials) = 0;


		// Abstract class destructor
		virtual ~AccountManagementHandler() noexcept = 0;  // must be virtual and pure
	};





	/*****************************************************************************
	** Inline implementations
	******************************************************************************/
	inline AccountManagementHandler::~AccountManagementHandler() noexcept
	{}


} // namespace AccountManagement



#endif //AccountManagement_AccountManagementHandler_h

