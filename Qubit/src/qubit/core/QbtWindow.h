#pragma once

#include "QbtPch.h"
#include "QbtCore.h"

namespace Qbt {

	class Window
	{
	private:


	public:
		virtual ~Window() {}

		virtual unsigned int GetWidth() = 0;
		virtual unsigned int GetHeight() = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSynced() = 0;
	};

}