#include "edpch.h"
#include "Endeavor/Renderer/Framebuffer.h"

#include "Endeavor/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace Endeavor {
	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:			ED_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:			return CreateRef<OpenGLFramebuffer>(spec);
		}

		ED_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
