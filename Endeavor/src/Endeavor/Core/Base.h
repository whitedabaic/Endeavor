#pragma once

#include "Endeavor/Core/PlatformDetection.h"

#include <memory>

#ifdef ED_DEBUG
	#if defined(ED_PLATFORM_WINDOWS)
		#define ED_DEBUGBREAK() __debugbreak()
	#elif defined(ED_PLATFORM_LINUX)
		#include <signal.h>
		#define ED_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define ED_ENABLE_ASSERTS
#else
	#define ED_DEBUGBREAK()
#endif

#define ED_EXPAND_MACRO(x) x
#define ED_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define ED_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }
namespace Endeavor {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

#include "Endeavor/Core/Log.h"
#include "Endeavor/Core/Assert.h"
