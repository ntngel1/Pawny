#pragma once

#ifdef PW_PLATFORM_WINDOWS
	#ifdef PW_BUILD_DLL
		#define PAWNY_API __declspec(dllexport)
	#else
		#define PAWNY_API __declspec(dllimport)
	#endif

#else
	#error Pawny only supports Windows!
#endif
