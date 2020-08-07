#include "QbtPch.h"
#include "qubit/core/QbtCore.h"
#include "qubit/core/Logger.h"
#include "GlWindow.h"

namespace Qbt {

	static bool s_IsGlfwInit = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new GlWindow(props);
	}

	GlWindow::GlWindow(const WindowProps& props)
	{
		GlWindow::Init(props);
	}

	GlWindow::~GlWindow()
	{
		GlWindow::Shutdown();
	}

	void GlWindow::Init(const WindowProps& props)
	{
		m_Data.m_Title  = props.m_Title;
		m_Data.m_Height = props.m_Height;
		m_Data.m_Width  = props.m_Width;

		QBT_LOG_INFO("Creating GlWindow ", props.m_Title, " as ", props.m_Width, "x", props.m_Height, ".");

		if (!s_IsGlfwInit)
		{
			int glfwInitSucc = glfwInit();
			QBT_ASSERT(!glfwInitSucc, "Glfw didn't get initialized!");

			s_IsGlfwInit = true;
		}

		m_WindowID = glfwCreateWindow((int)props.m_Width, (int)props.m_Height, props.m_Title.c_str(), 0, 0);
		glfwMakeContextCurrent(m_WindowID);
		glfwSetWindowUserPointer(m_WindowID, &m_Data);
		SetVSync(true);
	}

	void GlWindow::Shutdown()
	{
		glfwDestroyWindow(m_WindowID);
	}

	void GlWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_WindowID);
	}

	void GlWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		m_Data.m_IsVSynced = enabled;
	}

	bool GlWindow::IsVSynced() const
	{
		return m_Data.m_IsVSynced;
	}
}