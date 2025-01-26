#include <Endeavor.h>

class Sandbox : public Endeavor::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Endeavor::Application* Endeavor::CreateApplication()
{
	return new Sandbox();
}