#ifndef SimpleLogger_h
#define SimpleLogger_h

#include <string>
// #include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <vector>

namespace fs = boost::filesystem;

class Logger
{
public:
	Logger();
	~Logger();

	// all open functions return true on a successful open or true if the logger is already open
	// false otherwise
	bool open();
	bool open(const char* pPath);
	bool open(const fs::path pPath);

	// write a single message
	void write_log(const std::string& pMessage);
	// write a group of messages
	void write_log(const std::vector<std::string>& pMessages);

	// return true if the stream was successfully closed or if the stream was already closed
	// false otherwise
	bool close();

private:
	bool create_and_open();

private:
	fs::path mDir;
	fs::path mFile;
	fs::path mFull_path;
	std::ofstream mStream;

	// default values
	std::string mDefault_dir = "./";
	std::string mDefault_file = "log.log";
};
#endif SimpleLogger_h



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


