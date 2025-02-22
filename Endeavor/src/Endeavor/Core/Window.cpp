#include "edpch.h"
#include "Endeavor/Core/Window.h"

#ifdef ED_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Endeavor
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef ED_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		ED_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}