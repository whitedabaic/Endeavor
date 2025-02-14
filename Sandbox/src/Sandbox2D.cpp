#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{

}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Endeavor::Timestep ts)
{
	//Update
	m_CameraController.OnUpdate(ts);

	//Renderer
	Endeavor::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Endeavor::RenderCommand::Clear();

	Endeavor::Renderer2D::BeginScene(m_CameraController.GetCamera());

	Endeavor::Renderer2D::DrawQuad({ 0.0f, 0.0f }, { 1.0f, 1.0f }, { 0.8f, 0.2f, 0.3f, 1.0f });
	//std::dynamic_pointer_cast<Endeavor::OpenGLShader>(m_FlatColorShader)->Bind();
	//std::dynamic_pointer_cast<Endeavor::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

	Endeavor::Renderer2D::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Endeavor::Event& e)
{
	m_CameraController.OnEvent(e);
}
