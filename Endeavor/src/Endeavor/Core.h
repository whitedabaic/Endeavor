#pragma once

#ifdef  ED_PLATFORM_WINDOWS
	#ifdef ED_BUILD_DLL
		#define ENDEAVOR_API __declspec(dllexport)
	#else
		#define ENDEAVOR_API __declspec(dllimport)
	#endif
#else
	#error Endeavor only supports Windows!
#endif