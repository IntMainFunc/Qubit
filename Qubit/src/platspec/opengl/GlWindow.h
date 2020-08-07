#pragma once

#include "QbtPch.h"
#include "qubit/core/QbtCore.h"
#include "qubit/core/QbtWindow.h"

namespace Qbt {

	class GlWindow : public Window
	{
	private:
		struct WindowData
		{
			std::string m_Title;
			unsigned int m_Width, m_Height;
			bool m_IsVSynced;

			EventCallbackFunc m_EventCallbackFunc;

		};

		GLFWwindow* m_WindowID;
		WindowData m_Data;

		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	public:
		GlWindow(const WindowProps& props);
		~GlWindow();

		void OnUpdate() override;

		virtual unsigned int GetWidth() const override { return m_Data.m_Width; }
		virtual unsigned int GetHeight() const override { return m_Data.m_Height; };

		virtual void SetEventCallback(const EventCallbackFunc& callbackFunc) override { m_Data.m_EventCallbackFunc = callbackFunc; }

		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSynced() const override;
		
	};

}