#pragma once

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
	#define ED_ENABLE_ASSERTS
#endif

#ifdef ED_ENABLE_ASSERTS
	#define ED_ASSERT(x, ...) { if(!(x)) { ED_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ED_CORE_ASSERT(x, ...) { if(!(x)) { ED_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ED_ASSERT(x, ...)
	#define ED_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define ED_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)