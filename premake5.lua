workspace "Pawny"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Pawny"
	location "Pawny"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PW_PLATFORM_WINDOWS",
			"PW_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PW_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PW_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PW_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Pawny/vendor/spdlog/include",
		"Pawny/src"
	}

	links
	{
		"Pawny"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PW_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PW_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PW_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PW_DIST"
		optimize "On"