#pragma once

#include <memory>

#ifdef  ED_PLATFORM_WINDOWS
#if ED_DYNAMIC_LINK
	#ifdef ED_BUILD_DLL
		#define ENDEAVOR_API __declspec(dllexport)
	#else
		#define ENDEAVOR_API __declspec(dllimport)
	#endif
#else
	#define ENDEAVOR_API
#endif
#else
	#error Endeavor only supports Windows!
#endif

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

#ifdef ED_ENABLE_ASSERTS
	#define ED_ASSERT(x, ...) { if(!(x)) { ED_ERROR("Assertion Failed: {0}", __VA_ARGS__); ED_DEBUGBREAK(); } }
	#define ED_CORE_ASSERT(x, ...) { if(!(x)) { ED_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); ED_DEBUGBREAK(); } }
#else
	#define ED_ASSERT(x, ...)
	#define ED_CORE_ASSERT(x, ...)
#endif

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