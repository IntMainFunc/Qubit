#pragma once

#include <iostream>

#ifdef WINDOWS_BUILD
	#ifdef DEBUG_BUILD
		
		#include <string>
		#include <Windows.h>

		extern HANDLE consloeHandle;	

		template<typename T>
		static void printLoop(T arg)
		{
			std::cout << arg;
		}

		template<typename T>
		static void printLog(T arg)
		{
			std::cout << "[" << __TIME__ << "]: " << arg;
			std::cout << std::endl;
		}
		
		template<typename T, typename ... Ts>
		static void printLoop(T arg, Ts ... args)
		{
			std::cout << arg;
			printLoop(args ...);
		}
		
		template<typename T, typename ... Ts>
		static void printLog(T arg, Ts ... args)
		{
			std::cout << "[" << __TIME__ << "]: " << arg;
			printLoop(args ...);
			std::cout << std::endl;
		}

		#define LOG_CRIT(...)	SetConsoleTextAttribute(consloeHandle, 4);\
								printLog(__VA_ARGS__);\
								SetConsoleTextAttribute(consloeHandle, 15)
		#define LOG_EROR(...)	SetConsoleTextAttribute(consloeHandle, 12);\
								printLog(__VA_ARGS__);\
								SetConsoleTextAttribute(consloeHandle, 15)
		#define LOG_WARN(...)	SetConsoleTextAttribute(consloeHandle, 14);\
								printLog(__VA_ARGS__);\
								SetConsoleTextAttribute(consloeHandle, 15)
		#define LOG_INFO(...)	SetConsoleTextAttribute(consloeHandle, 15);\
								printLog(__VA_ARGS__)
		#define LOG_SUCC(...)	SetConsoleTextAttribute(consloeHandle, 10);\
								printLog(__VA_ARGS__);\
								SetConsoleTextAttribute(consloeHandle, 15)
		#define LOG_IF(x,y)		if(x){y}

	#else // DEBUG_BUILD

		#define LOG_CRIT(...)
		#define LOG_EROR(...)
		#define LOG_WARN(...)
		#define LOG_INFO(...)
		#define LOG_SUCC(...)
		#define LOG_IF(x,y)

	#endif // DEBUG_BUILD
#endif // WINDOWS_BUILD