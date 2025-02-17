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
	Sandbox()
	{
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}
};

Endeavor::Application* Endeavor::CreateApplication()
{
	return new Sandbox();
}