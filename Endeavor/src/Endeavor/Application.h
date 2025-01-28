#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Endeavor {
	class ENDEAVOR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//定义在客户端
	Application* CreateApplication();
}