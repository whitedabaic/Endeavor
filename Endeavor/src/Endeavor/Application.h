#pragma once

#include "Core.h"

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