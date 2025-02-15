#pragma once

#include "Endeavor.h"

class Sandbox2D : public Endeavor::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Endeavor::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Endeavor::Event& e) override;
private:
	Endeavor::OrthographicCameraController m_CameraController;

	// TEMP
	Endeavor::Ref<Endeavor::VertexArray> m_SquareVA;
	Endeavor::Ref<Endeavor::Shader> m_FlatColorShader;

	Endeavor::Ref<Endeavor::Texture2D> m_CheckboardTexture;

	struct ProfileResult
	{
		const char* Name;
		float Time;
	};

	std::vector<ProfileResult> m_ProfileResults;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

};