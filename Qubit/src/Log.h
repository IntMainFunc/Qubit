#pragma once

#include <iostream>

#ifdef WINDOWS_BUILD
	#ifdef DEBUG_BUILD

		#include <Windows.h>
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		auto setColor = SetConsoleTextAttribute;

		#define LOG_CRIT(x) setColor(h, 4); std::cout << "[" << __TIME__ << "]: " << x << std::endl; setColor(h,15)
		#define LOG_ERR(x) setColor(h, 12); std::cout << "[" << __TIME__ << "]: " << x << std::endl; setColor(h,15)
		#define LOG_WARN(x) setColor(h,14); std::cout << "[" << __TIME__ << "]: " << x << std::endl; setColor(h,15)
		#define LOG_INFO(x) setColor(h,15); std::cout << "[" << __TIME__ << "]: " << x << std::endl; setColor(h,15)
		#define LOG_SUCC(x) setColor(h,10); std::cout << "[" << __TIME__ << "]: " << x << std::endl; setColor(h,15)
		#define LOG_IF(x,y) if(x){y}

	#else // DEBUG_BUILD 

		#define LOG_CRIT(x)
		#define LOG_ERR(x)
		#define LOG_WARN(x)
		#define LOG_INFO(x)
		#define LOG_SUCC(x)
		#define LOG_IF(x,y)

	#endif // DEBUG_BUILD
#endif // WINDOWS_BUILD