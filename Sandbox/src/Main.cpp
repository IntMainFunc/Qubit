#include "Qubit.h"

class Sandbox : public qbt::App
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
		while (true)
		{
			break;
		}
	}
};

int main()
{	
	Sandbox* sandboxApp = new Sandbox();
	sandboxApp->Run();
	delete sandboxApp;
}