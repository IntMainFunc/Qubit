#include "Log.h"

#ifdef WINDOWS_BUILD
	#ifdef DEBUG_BUILD
	
		HANDLE consloeHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	#else // DEBUG_BUILD
	
	#endif // DEBUG_BUILD
#endif // WINDOWS_BUILD