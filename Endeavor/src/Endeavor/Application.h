#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Endeavor {
	class ENDEAVOR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//定义在客户端
	Application* CreateApplication();
}