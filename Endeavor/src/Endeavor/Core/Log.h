#pragma once

#include "Endeavor/Core/Base.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Endeavor {
	class ENDEAVOR_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define ED_CORE_TRACE(...)	::Endeavor::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ED_CORE_INFO(...)	::Endeavor::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ED_CORE_WARN(...)	::Endeavor::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ED_CORE_ERROR(...)	::Endeavor::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ED_CORE_FATAL(...)	::Endeavor::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define ED_TRACE(...)		::Endeavor::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ED_INFO(...)		::Endeavor::Log::GetClientLogger()->info(__VA_ARGS__)
#define ED_WARN(...)		::Endeavor::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ED_ERROR(...)		::Endeavor::Log::GetClientLogger()->error(__VA_ARGS__)
#define ED_FATAL(...)		::Endeavor::Log::GetClientLogger()->fatal(__VA_ARGS__)