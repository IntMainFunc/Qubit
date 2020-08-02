#pragma once

#include "QbtPch.h"
#include "QbtCore.h"

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