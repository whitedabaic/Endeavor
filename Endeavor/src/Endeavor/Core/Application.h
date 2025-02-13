#pragma once

#include "Core.h"

#include "Window.h"
#include "Endeavor/Core/LayerStack.h"
#include "Endeavor/Events/Event.h"
#include "Endeavor/Events/ApplicationEvent.h"

#include "Endeavor/Core/Timestep.h"

#include "Endeavor/ImGui/ImGuiLayer.h"

namespace Endeavor {
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		Timestep m_Timestep;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	//定义在客户端
	Application* CreateApplication();
}