#ifndef SimpleLogger_h
#define SimpleLogger_h

#include <fstream>

// Use the namespace you want
namespace Logger {

	class SimpleLogger {

	public:
		// If you can´t/dont-want-to use C++11, remove the "class" word after enum
		enum e_logType { LOG_ERROR, LOG_WARNING, LOG_INFO, LOG_LOGINSUCCESS, LOG_UISUCCESS,
			LOG_DOWNSUCCESS
		};


		// ctor (remove parameters if you don´t need them)
		explicit SimpleLogger(const char *engine_version, const char *fname = "Logger_log.txt")
			: numWarnings(0U),
			numErrors(0U), numUISuccess(0U), numLoginSuccess(0U), numDownSuccess(0U)
		{

			myFile.open(fname);

			// Write the first lines
			if (myFile.is_open()) {
				myFile << "Tetris Game, version " << engine_version << std::endl;
				myFile << "Log File Created" << std::endl << std::endl;
			} // if

		}


		// dtor
		~SimpleLogger() {

			if (myFile.is_open()) {
				myFile << std::endl << std::endl;

				//Report if successful login
				myFile << numUISuccess << " UI successful" << std::endl;
				myFile << numLoginSuccess << " Login successful" << std::endl;
				myFile << numDownSuccess << " Shut Down successful" << std::endl;

				// Report number of errors and warnings
				myFile << numWarnings << " warnings" << std::endl;
				myFile << numErrors << " errors" << std::endl;

				myFile.close();
			} // if

		}


		// Overload << operator using log type
		friend SimpleLogger &operator << (SimpleLogger &logger, const e_logType l_type) {

			switch (l_type) {
			case Logger::SimpleLogger::e_logType::LOG_ERROR:
				logger.myFile << "[ERROR]: ";
				++logger.numErrors;
				break;

			case Logger::SimpleLogger::e_logType::LOG_WARNING:
				logger.myFile << "[WARNING]: ";
				++logger.numWarnings;
				break;

			case Logger::SimpleLogger::e_logType::LOG_LOGINSUCCESS:
				logger.myFile << "[LOGIN USED]: ";
				++logger.numLoginSuccess;
				break;

			case Logger::SimpleLogger::e_logType::LOG_UISUCCESS:
				logger.myFile << "[UI USED]: ";
				++logger.numUISuccess;
				break;

			case Logger::SimpleLogger::e_logType::LOG_DOWNSUCCESS:
				logger.myFile << "[SHUT DOWN USED]: ";
				++logger.numDownSuccess;
				break;

			default:
				logger.myFile << "[INFO]: ";
				break;
			} // sw


			return logger;

		}


		// Overload << operator using C style strings
		// No need for std::string objects here
		friend SimpleLogger &operator << (SimpleLogger &logger, const char *text) {

			logger.myFile << text << std::endl;
			return logger;

		}


		// Make it Non Copyable (or you can inherit from sf::NonCopyable if you want)
		SimpleLogger(const SimpleLogger &) = delete;
		SimpleLogger &operator= (const SimpleLogger &) = delete;



	private:

		std::ofstream           myFile;

		unsigned int            numWarnings;
		unsigned int            numErrors;
		unsigned int			numUISuccess;
		unsigned int			numLoginSuccess;
		unsigned int			numDownSuccess;

	}; // class end

}  // namespace


#endif // SimpleLogger_h
















/*#ifndef SimpleLogger_h
#define SimpleLogger_h

#include <iostream>
#include <chrono>
#include <iomanip>

#include "LoggerHandler.h"


namespace Logging
{
	class SimpleLogger : public LoggerHandler
	{
	public:
		//Constructors
		using LoggerHandler::LoggerHandler;                       // inherent constructors
		SimpleLogger(std::ostream & loggingStream = std::clog);  // default ctor

																 // Operations
		SimpleLogger & operator<< (const std::string & message) override;

		// Destructor
		~SimpleLogger() noexcept override;
	}; // class SimpleLogger






	   *****************************************************************************
	   ** Inline implementations
	   ******************************************************************************
	inline SimpleLogger::SimpleLogger(std::ostream & loggingStream)
		: LoggerHandler(loggingStream)
	{
		// Let's set the buffering behavior of the stream so the order and context of inserted information is preserved. Force the
		// buffer to be flushed after each insertion. One normally doesn't want to do this, but log files are very often viewed in real
		// time as the program executes (e.g. tailing a file).  Waiting for the buffer to fill before seeing the contents may give false
		// information in such cases.  
		loggingStream << std::unitbuf;

		*this << "Simple Logger being used and has been successfully initialized";
	}


	inline SimpleLogger::~SimpleLogger() noexcept
	{
		*this << "Simple Logger shutdown successfully";
	}



	inline SimpleLogger & SimpleLogger::operator<< (const std::string & message)
	{
		auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

#pragma warning(suppress : 4996)  // acknowledge and accept that std::localtime is not thread safe (Turn off MSVC++ warning)
		_loggingStream << std::put_time(std::localtime(&now), "%Y-%m-%d %X") << " | ";

		_loggingStream << message << '\n';

		return *this;
	}

} // namespace TechicalServices::Logging


#endif // TechicalServices_Logging_SimpleLogger_hpp*/


