#pragma once

#include "Endeavor/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Endeavor {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};

}