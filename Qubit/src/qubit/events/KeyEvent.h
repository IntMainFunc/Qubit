#pragma once

#include "QbtPch.h"
#include "qubit/core/QbtCore.h"
#include "CoreEvent.h"

namespace Qbt {

	class KeyEvent : public Event
	{
	protected:
		KeyEvent(unsigned int keyCode)
			:m_KeyCode(keyCode) { }

		unsigned int m_KeyCode;

	public:
		static EventType GetStatType() { return EventType::Base; }
		virtual EventType GetType() const override { return GetStatType(); }

		unsigned int GetKeyCode() const { return m_KeyCode; }

		virtual std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << m_KeyCode;
			return ss.str();
		}
	};

	class KeyPressEvent : public KeyEvent
	{
	private:
		unsigned int m_RepeatCount;

	public:
		KeyPressEvent(unsigned int keyCode, unsigned int repeatCount)
			:KeyEvent(keyCode), m_RepeatCount(repeatCount) { }

		static EventType GetStatType() { return EventType::KeyPress; }
		EventType GetType() const override { return GetStatType(); }

		unsigned int GetRepeatCount() const { return m_RepeatCount; }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			if (m_RepeatCount)
			{
				ss << m_KeyCode << " key repeated " << m_RepeatCount << " time/s.";
			}
			else
			{
				ss << m_KeyCode << " key pressed.";
			}
			return ss.str();
		}

	};

	class KeyReleaseEvent : public KeyEvent
	{
	private:

	public:
		KeyReleaseEvent(unsigned int keyCode)
			:KeyEvent(keyCode) { }

		static EventType GetStatType() { return EventType::KeyRelease; }
		EventType GetType() const override { return GetStatType(); }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << m_KeyCode << " key released.";
			return ss.str();
		}

	};

}