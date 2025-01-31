#include <Endeavor.h>

#include "imgui/imgui.h"

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

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World!");
		ImGui::End();
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
	}

	~Sandbox()
	{

	}
};

Endeavor::Application* Endeavor::CreateApplication()
{
	return new Sandbox();
}