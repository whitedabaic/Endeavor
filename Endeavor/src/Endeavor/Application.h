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

	//�����ڿͻ���
	Application* CreateApplication();
}