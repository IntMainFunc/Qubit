#pragma once

/*
	This part of QubitCore.h
	identified the platform used
	and defines a macro for use
	in source file in the Qubit API.
*/

// Start of platform identification
//----------------------------------
#ifdef _WIN32									// _WIN32 - Windows x32/x64/x86
	#define QBT_WINDOWS_PLATFORM

	#ifdef _WIN64								// _WIN64 - Windows x64
		#define QBT_WINDOWS_X64_PLATFORM

	#else										// _WIN64(else) - Windows x32/x86
		#define QBT_WINDOWS_X32_PLATFORM
		#error x86/x32 Windows is currently not supported.

	#endif										
#elif defined(__APPLE__) || defined(__MACH__)	// __APPLE__ & __MACH__ - Apple
	#define QBT_APPLE_PLATFORM
	#error Apple is not currently supported.

#elif defined(__ANDROID__)						// __ANDROID__ - Android
	#define QBT_ANDROID_PLATFORM
	#error Android is not currently supported.

#elif defined(__linux__)						// __linux__ - Linux
	#define QBT_LINUX_PLATFORM
	#error Linux is not currently supported.

#else											// No macro - Unidentified platform.
	#error Unknown platform not supported.

#endif 
// End of platform identification
//--------------------------------