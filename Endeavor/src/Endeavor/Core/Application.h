#pragma once

#include "Endeavor/Core/Base.h"

#include "Window.h"
#include "Endeavor/Core/LayerStack.h"
#include "Endeavor/Events/Event.h"
#include "Endeavor/Events/ApplicationEvent.h"

#include "Endeavor/Core/Timestep.h"

#include "Endeavor/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Endeavor {
	class Application
	{
	public:
		Application(const std::string& name = "Endeavor App");
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		Timestep m_Timestep;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	//定义在客户端
	Application* CreateApplication();
}
