#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Pawny {

	class PAWNY_API Log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() 
		{
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define PW_CORE_ERROR(...) ::Pawny::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PW_CORE_WARN(...)  ::Pawny::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PW_CORE_INFO(...)  ::Pawny::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PW_CORE_TRACE(...) ::Pawny::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define PW_ERROR(...)	   ::Pawny::Log::GetClientLogger()->error(__VA_ARGS__)
#define PW_WARN(...)	   ::Pawny::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PW_INFO(...)	   ::Pawny::Log::GetClientLogger()->info(__VA_ARGS__)
#define PW_TRACE(...)	   ::Pawny::Log::GetClientLogger()->trace(__VA_ARGS__)