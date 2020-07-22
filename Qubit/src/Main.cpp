#include "Log.h"

int main()
{		
	LOG_CRIT("Test", 1, 2, 3, 'a', 'b', 'c');
	LOG_EROR("Test", 1, 2, 3, 'a', 'b', 'c');
	LOG_WARN("Test", 1, 2, 3, 'a', 'b', 'c');
	LOG_INFO("Test", 1, 2, 3, 'a', 'b', 'c');
	LOG_SUCC("Test", 1, 2, 3, 'a', 'b', 'c');

}