#pragma once

#include "QbtPch.h"
#include "CoreEvent.h"

namespace Qbt {

	class MouseButtonEvent : public Event
	{
	protected:
		MouseButtonEvent(unsigned int button)
			:m_Button(button) { }

		unsigned int m_Button;

	public:
		static EventType GetStatType() { return EventType::Base; }
		virtual EventType GetType() const override { return GetStatType(); }

		unsigned int GetButton() const { return m_Button; }

		virtual std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << m_Button;
			return ss.str();
		}

	};

	class MousePressEvent : public MouseButtonEvent
	{
	public:
		MousePressEvent(unsigned int button)
			:MouseButtonEvent(button) { }

		static EventType GetStatType() { return EventType::MousePress; }
		EventType GetType() const override { return GetStatType(); }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << m_Button << " pressed.";
			return ss.str();
		}

	};

	class MouseReleaseEvent : public MouseButtonEvent
	{
	public:
		MouseReleaseEvent(unsigned int button)
			:MouseButtonEvent(button) { }

		static EventType GetStatType() { return EventType::MouseRelease; }
		EventType GetType() const override { return GetStatType(); }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << m_Button << " released.";
			return ss.str();
		}

	};

	class MouseMoveEvent : public Event
	{
	private:
		float m_OffsetX, m_OffsetY;

	public:
		MouseMoveEvent(float offsetX, float offsetY)
			:m_OffsetX(offsetX), m_OffsetY(offsetY) { }

		static EventType GetStatType() { return EventType::MouseMove; }
		EventType GetType() const override { return GetStatType(); }

		float GetOffsetX() const { return m_OffsetX; }
		float GetOffsetY() const { return m_OffsetY; }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "Mouse moved X: " << m_OffsetX << " Y: " << m_OffsetY << '.';
			return ss.str();
		}

	};

	class MouseScrollEvent : public Event
	{
	private:
		float m_OffsetX, m_OffsetY;

	public:
		MouseScrollEvent(float offsetX, float offsetY)
			:m_OffsetX(offsetX), m_OffsetY(offsetY) { }

		static EventType GetStatType() { return EventType::MouseScroll; }
		EventType GetType() const override { return GetStatType(); }

		float GetOffsetX() const { return m_OffsetX; }
		float GetOffsetY() const { return m_OffsetY; }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "Mouse scrolled X: " << m_OffsetX << " Y: " << m_OffsetY << '.';
			return ss.str();
		}

	};

}