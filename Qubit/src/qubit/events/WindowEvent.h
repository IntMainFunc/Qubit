#pragma once

#include "QbtPch.h"
#include "qubit/core/QbtCore.h"
#include "CoreEvent.h"

namespace Qbt {

	class WindowResizeEvent : public Event
	{
	private:
		unsigned int m_Width, m_Height;

	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			:m_Width(width), m_Height(height) { }

		static EventType GetStatType() { return EventType::WindowResize; }
		EventType GetType() const override { return GetStatType(); }

		unsigned int GetWidth() const { return m_Width; }
		unsigned int GetHeight() const { return m_Height; }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "Resized window to X: " << m_Width << " Y: " << m_Height << '.';
			return ss.str();
		}

	};

	class WindowCloseEvent : public Event
	{
	public:
		static EventType GetStatType() { return EventType::WindowResize; }
		EventType GetType() const override { return GetStatType(); }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "Window closed.";
			return ss.str();
		}

	};

	class WindowFocusEvent : public Event
	{
	public:
		static EventType GetStatType() { return EventType::WindowFocus; }
		EventType GetType() const override { return GetStatType(); }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "Window focused.";
			return ss.str();
		}

	};

	class WindowUnfocusEvent : public Event
	{
	public:
		static EventType GetStatType() { return EventType::WindowUnfocus; }
		EventType GetType() const override { return GetStatType(); }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "Window Unfocused.";
			return ss.str();
		}

	};

}