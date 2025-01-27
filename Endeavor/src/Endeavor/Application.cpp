#include "Application.h"

#include "Endeavor/Events/ApplicationEvent.h"
#include "Endeavor/Log.h"

namespace Endeavor {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			ED_TRACE("Event: {}", e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			ED_TRACE("Event: {}", e.ToString());
		}

		while (true);
	}
}