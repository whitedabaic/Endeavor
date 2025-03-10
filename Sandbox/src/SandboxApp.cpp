#include <Endeavor.h>
#include <Endeavor/Core/EntryPoint.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"

class Sandbox : public Endeavor::Application
{
public:
	Sandbox(const Endeavor::ApplicationSpecification& specification)
		: Endeavor::Application(specification)
	{
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}
};

Endeavor::Application* Endeavor::CreateApplication(Endeavor::ApplicationCommandLineArgs args)
{
	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = "../Endeacor-Editor";
	spec.CommandLineArgs = args;

	return new Sandbox(spec);
}
