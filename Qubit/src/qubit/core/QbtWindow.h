#pragma once

#include "QbtPch.h"
#include "QbtCore.h"
#include "qubit/events/CoreEvent.h"

namespace Qbt {

	struct WindowProps
	{
		std::string m_Title;
		unsigned int m_Width, m_Height;

		WindowProps(const std::string title = "Qubit engine window", unsigned int width = 1280, unsigned int height = 720)
			:m_Title(title), m_Width(width), m_Height(height) { }
	};

	class Window
	{
	protected:
		using EventCallbackFunc = std::function<void(Event&)>;

	public:
		virtual ~Window() { }

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
			
		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSynced() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}