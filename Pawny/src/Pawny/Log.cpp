#include "Log.h"

namespace Pawny {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		const std::string pattern = "%^[%T] %n: %v%$";
		spdlog::set_pattern(pattern);

		s_CoreLogger = spdlog::stdout_color_mt("PAWNY");
		s_CoreLogger->set_level(spdlog::level::trace);
		
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}	

}