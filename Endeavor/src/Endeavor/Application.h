#pragma once

#include "Core.h"

#include "Window.h"
#include "Endeavor/LayerStack.h"
#include "Endeavor/Events/Event.h"
#include "Endeavor/Events/ApplicationEvent.h"


namespace Endeavor {
	class ENDEAVOR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//�����ڿͻ���
	Application* CreateApplication();
}