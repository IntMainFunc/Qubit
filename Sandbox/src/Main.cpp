#include <Qubit.h>

class Sandbox : public Qbt::App
{
public:
	Sandbox()
	{
		QBT_LOG_INFO("Sandbox app started!");
	}

	~Sandbox()
	{
		QBT_LOG_INFO("Sandbox app closed!");
	}

	void Run()
	{
		while (m_IsRunning)
		{
			m_Window->OnUpdate();
		}
	}
};

int main()
{	
	Sandbox* sandboxApp = new Sandbox();
	sandboxApp->Run();
	delete sandboxApp;
}