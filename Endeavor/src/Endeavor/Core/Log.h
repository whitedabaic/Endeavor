#pragma once

#include "Endeavor/Core/Base.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#pragma warning(pop)

namespace Endeavor {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
	return os << glm::to_string(quaternion);
}

// Core log macros
#define ED_CORE_TRACE(...)		::Endeavor::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ED_CORE_INFO(...)		::Endeavor::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ED_CORE_WARN(...)		::Endeavor::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ED_CORE_ERROR(...)		::Endeavor::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ED_CORE_CRITICAL(...)	::Endeavor::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define ED_TRACE(...)			::Endeavor::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ED_INFO(...)			::Endeavor::Log::GetClientLogger()->info(__VA_ARGS__)
#define ED_WARN(...)			::Endeavor::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ED_ERROR(...)			::Endeavor::Log::GetClientLogger()->error(__VA_ARGS__)
#define ED_CRITICAL(...)		::Endeavor::Log::GetClientLogger()->critical(__VA_ARGS__)
