#pragma once

// The Qubit precompiled header
//------------------------------

//Core.
#include "qubit\core\QbtCore.h"

//Basic.
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <functional>

//DataStructs.
#include <string>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

//Platform APIs.
#ifdef QBT_WINDOWS_PLATFORM
	#include <Windows.h>
#endif