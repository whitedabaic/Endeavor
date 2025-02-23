#pragma once

#include "Endeavor/Core/PlatformDetection.h"

#ifdef ED_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
		#define NOMINMAX
	#endif
#endif

#include <iostream>
#include <memory>5
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Endeavor/Core/Log.h"

#include "Endeavor/Debug/Instrumentor.h"

#ifdef ED_PLATFORM_WINDOWS
	#include <Windows.h>
#endif