#pragma once

#include "Endeavor/Core/Base.h"
#include "Endeavor/Core/Log.h"
#include <filesystem>

#ifdef ED_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define ED_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { ED##type##ERROR(msg, __VA_ARGS__); ED_DEBUGBREAK(); } }
#define ED_INTERNAL_ASSERT_WITH_MSG(type, check, ...) ED_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define ED_INTERNAL_ASSERT_NO_MSG(type, check) ED_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", ED_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)
#define ED_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define ED_INTERNAL_ASSERT_GET_MACRO(...) ED_EXPAND_MACRO( ED_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, ED_INTERNAL_ASSERT_WITH_MSG, ED_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define ED_ASSERT(...) ED_EXPAND_MACRO( ED_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define ED_CORE_ASSERT(...) ED_EXPAND_MACRO( ED_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define ED_ASSERT(...)
#define ED_CORE_ASSERT(...)
#endif
