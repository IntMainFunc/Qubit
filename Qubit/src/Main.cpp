#include "Log.h"

int main()
{
	LOG_CRIT("Test");
	LOG_ERR("Test");
	LOG_WARN("Test");
	LOG_INFO("Test");
	LOG_SUCC("Test");

	int n = 32;
	float f = n;
}