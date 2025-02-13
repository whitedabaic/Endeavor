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
	m_SquareVA = Endeavor::VertexArray::Create();

	float squareVertices[5 * 4] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	Endeavor::Ref<Endeavor::VertexBuffer> squareVB;
	squareVB.reset(Endeavor::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
	squareVB->SetLayout({
		{ Endeavor::ShaderDataType::Float3, "a_Position" }
		});
	m_SquareVA->AddVertexBuffer(squareVB);

	uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
	Endeavor::Ref<Endeavor::IndexBuffer> squareIB;
	squareIB.reset(Endeavor::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
	m_SquareVA->SetIndexBuffer(squareIB);

	m_FlatColorShader = Endeavor::Shader::Create("assets/shaders/FlatColor.glsl");
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

	Endeavor::Renderer::BeginScene(m_CameraController.GetCamera());

	std::dynamic_pointer_cast<Endeavor::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<Endeavor::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

	Endeavor::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

	Endeavor::Renderer::EndScene();
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
