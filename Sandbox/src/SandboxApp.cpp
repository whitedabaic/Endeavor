#include <Endeavor.h>

class ExampleLayer : public Endeavor::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}
	void OnUpdate() override
	{
		ED_INFO("ExampleLayer::Update");
	}
	void OnEvent(Endeavor::Event& event) override
	{
		ED_TRACE("{0}", event.ToString());
	}
};
class Sandbox : public Endeavor::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Endeavor::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Endeavor::Application* Endeavor::CreateApplication()
{
	return new Sandbox();
}