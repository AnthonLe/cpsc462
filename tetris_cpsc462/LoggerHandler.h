#ifndef LoggerHandler_h
#define LoggerHandler_h


#include <iostream>
#include <string>


namespace Logging
{
	// Logging Package within the Technical Services Layer Abstract class
	class LoggerHandler
	{
	public:
		// Constructors and assignment operations
		LoggerHandler(std::ostream & loggingStream = std::clog);           // default ctor
		LoggerHandler(const LoggerHandler &  original) = default;  // copy ctor
		LoggerHandler(LoggerHandler && original) = default;  // move ctor

		virtual LoggerHandler & operator=(const LoggerHandler &  rhs) = default;  // copy assignment
		virtual LoggerHandler & operator=(LoggerHandler && rhs) = default;  // move assignment


																			// Operations
		virtual LoggerHandler & operator<< (const std::string & message) = 0;

		// Destructor
		// Pure virtual destructor helps force the class to be abstract, but must still be implemented
		virtual ~LoggerHandler() noexcept = 0;


	protected:
		std::ostream & _loggingStream;
	};



	/*****************************************************************************
	** Inline default implementations
	******************************************************************************/
	inline LoggerHandler::~LoggerHandler() noexcept
	{}


	inline LoggerHandler::LoggerHandler(std::ostream & loggingStream)
		: _loggingStream(loggingStream)
	{}
} // namespace TechicalServices::Logging



#endif // TechicalServices_Logging_LoggerHandler_hpp

