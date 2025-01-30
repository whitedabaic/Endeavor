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

		if (Endeavor::Input::IsKeyPressed(ED_KEY_TAB))
			ED_TRACE("Tab key is pressed (poll)!");
	}
	void OnEvent(Endeavor::Event& event) override
	{
		if (event.GetEventType() == Endeavor::EventType::KeyPressed)
		{
			Endeavor::KeyPressedEvent& e = (Endeavor::KeyPressedEvent&)event;
			if (e.GetKeyCode() == ED_KEY_TAB)
				ED_TRACE("Tab key is pressed (event)!");
			ED_TRACE("{0}", (char)e.GetKeyCode());
		}
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