#pragma once

#include "QubitCore.h"

namespace qbt {
	
	class App
	{
	private:
	
	public:
		App();
		~App();
	
		virtual void Run() = 0;
	};
	
}