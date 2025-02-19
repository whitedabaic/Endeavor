#pragma once

#include "Endeavor.h"

#include "ParticleSystem.h"

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
	Endeavor::Ref<Endeavor::Texture2D> m_SpriteSheet;
	Endeavor::Ref<Endeavor::SubTexture2D> m_TextureStairs;
	Endeavor::Ref<Endeavor::SubTexture2D> m_TextureBarrel;
	Endeavor::Ref<Endeavor::SubTexture2D> m_TextureTree;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

	ParticleSystem m_ParticleSystem;
	ParticleProps m_Particle;

	uint32_t m_MapWidth, m_MapHeight;
	std::unordered_map<char, Endeavor::Ref<Endeavor::SubTexture2D>> s_TextureMap;
};