#pragma once

#include "Endeavor/Core/Base.h"

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

		Window& GetWindow() { return *m_Window; }

		void Close();

		static Application& Get() { return *s_Instance; }
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