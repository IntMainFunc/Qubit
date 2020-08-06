#pragma once

#include "QbtPch.h"
#include "QbtCore.h"

namespace Qbt {
	
	class App
	{
	private:
	
	public:
		App();
		~App();
	
		virtual void Run() = 0;
	};
	
}