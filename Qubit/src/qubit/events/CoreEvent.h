#pragma once

#include "QbtPch.h"
#include "qubit/core/QbtCore.h"

namespace Qbt {

	enum class EventType
	{
		None = -1, Base = 0,
		WindowClose, WindowResize, WindowFocus, WindowUnfocus, WindowMove,
		KeyPress, KeyRelease,
		MousePress, MouseRelease, MouseMove, MouseScroll
	};

	class Event
	{
	private:
		friend class EventDispatcher;

	protected:
		bool m_Handled = false;

	public:
		virtual EventType GetType() const = 0;
		virtual std::string GetDebug() const = 0;

	};

	class EventDispatcher
	{
	private:
		Event& m_Event;

	public:
		EventDispatcher(Event& event)
			:m_Event(event) { }

		template<typename T>
		bool Dispatch(std::function<bool(T&)> func)
		{
			if (m_Event.GetType() == T::GetStatType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	};

}