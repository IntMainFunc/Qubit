#include "QbtPch.h"
#include "Logger.h"
#include "QbtCore.h"

#ifdef QBT_WINDOWS_PLATFORM
HANDLE loggingConsole = GetStdHandle(STD_OUTPUT_HANDLE);

#endif