#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	ED_PROFILE_FUNCTION();

	m_CheckboardTexture = Endeavor::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	ED_PROFILE_FUNCTION();

}

void Sandbox2D::OnUpdate(Endeavor::Timestep ts)
{
	ED_PROFILE_FUNCTION();
	//Update
	m_CameraController.OnUpdate(ts);

	//Renderer
	Endeavor::Renderer2D::ResetStats();
	{
		ED_PROFILE_SCOPE("Renderer Prep");
		Endeavor::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Endeavor::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 20.0f;

		ED_PROFILE_SCOPE("Renderer Draw");
		Endeavor::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Endeavor::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		Endeavor::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Endeavor::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Endeavor::Renderer2D::DrawQuad({ 0.0f,  0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckboardTexture, 10.0f);
		Endeavor::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckboardTexture, 20.0f);
		Endeavor::Renderer2D::EndScene();

		Endeavor::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				Endeavor::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		Endeavor::Renderer2D::EndScene();

	}
}

void Sandbox2D::OnImGuiRender()
{
	ED_PROFILE_FUNCTION();
	ImGui::Begin("Settings");

	auto stats = Endeavor::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Endeavor::Event& e)
{
	m_CameraController.OnEvent(e);
}
