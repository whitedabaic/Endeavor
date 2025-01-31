#include "edpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Endeavor {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		ED_CORE_ASSERT(windowHandle, "Window handle is null!");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ED_CORE_ASSERT(status, "Failed to initialize Glad!");

		ED_CORE_INFO("  Vendor: {}", std::string(reinterpret_cast<const char*>(glGetString(GL_VENDOR))));
		ED_CORE_INFO("  Renderer: {}", std::string(reinterpret_cast<const char*>(glGetString(GL_RENDERER))));
		ED_CORE_INFO("  Version: {}", std::string(reinterpret_cast<const char*>(glGetString(GL_VERSION))));
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}