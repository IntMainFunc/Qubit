#pragma once

#include "QbtPch.h"
#include "QbtCore.h"

#ifdef QBT_WINDOWS_PLATFORM
	extern HANDLE loggingConsole;

#endif // QBT_WINDOWS_PLATFORM


namespace qbt {

	class Logger
	{
	private:
		Logger()
		{

		}

	public:
	#ifdef QBT_WINDOWS_PLATFORM // Windows platform x32/x64/x86
		enum Level
		{
			None    = 0,
			Clear   = 15,
			Info    = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
			Warning = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
			Error   = FOREGROUND_INTENSITY | FOREGROUND_RED,
			Fatal   = FOREGROUND_RED
		};

	#else
		enum Level
		{
			None    = 0,
			Clear   = 0,
			Info,
			Warning,
			Error,
			Fatal
		};

	#endif // Windows platform x32/x64/x86

		template<typename T>
		static void LogMassage(T Data)
		{
			std::cout << Data << std::endl;
		}

		template<typename T, typename ... Ts>
		static void LogMassage(T Data, Ts ... Data_s)
		{
			std::cout << Data;
			LogLoop(Data_s);
		}

	};

}

#if defined(QBT_DEBUG_BUILD) || defined(QBT_RELEASE_BUILD)
	#ifdef QBT_WINDOWS_PLATFORM // Windows platform x32/x64/x86
		#define QBT_LOG_INFO(...) \
		SetConsoleTextAttribute(loggingConsole, qbt::Logger::Info);\
		qbt::Logger::LogMassage(__VA_ARGS__);\
		SetConsoleTextAttribute(loggingConsole, qbt::Logger::Clear)
		
		#define QBT_LOG_WARN(...) \
		SetConsoleTextAttribute(loggingConsole, qbt::Logger::Warning);\
		qbt::Logger::LogMassage(__VA_ARGS__);\
		SetConsoleTextAttribute(loggingConsole, qbt::Logger::Clear)
		
		#define QBT_LOG_ERROR(...) \
		SetConsoleTextAttribute(loggingConsole, qbt::Logger::Error);\
		qbt::Logger::LogMassage(__VA_ARGS__);\
		SetConsoleTextAttribute(loggingConsole, qbt::Logger::Clear)
		
		#define QBT_LOG_FATAL(...) \
		SetConsoleTextAttribute(loggingConsole, qbt::Logger::Fatal);\
		qbt::Logger::LogMassage(__VA_ARGS__);\
		SetConsoleTextAttribute(loggingConsole, qbt::Logger::Clear)
		
	#else		
	#endif
#else
	#define QBT_LOG_INFO(...)
	#define QBT_LOG_WARN(...)
	#define QBT_LOG_ERROR(...)
	#define QBT_LOG_FATAL(...)

#endif