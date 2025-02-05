#include "edpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Endeavor {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}