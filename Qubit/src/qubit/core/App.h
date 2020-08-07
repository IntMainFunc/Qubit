#pragma once

#include "QbtPch.h"
#include "QbtCore.h"
#include "QbtWindow.h"

namespace Qbt {
	
	class App
	{
	protected:
		Window* m_Window;
		bool m_IsRunning;
	
	public:
		App();
		~App();
	
		virtual void Run() = 0;

	};
	
}