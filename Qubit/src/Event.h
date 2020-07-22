#pragma once

enum class EventType
{
	None = 0,
	WindowClose, WindowResize, WindowFocus, WindowUnfocus,
	KeyPress, KeyRelease,
	MouseClick, MouseClickRelease, MouseMove, MouseScroll
};

enum class EventCategory
{
	None = 0,
	Application =	(1 << 0),
	Input =			(1 << 1),
	Keyboard =		(1 << 2),
	Mouse =			(1 << 3),
	MouseButton =	(1 << 4)
};

template<EventType ET, EventCategory EC>
class Event
{
private:

protected:

public:
	constexpr EventType GetEventType();
	constexpr const char* GetName();

};
