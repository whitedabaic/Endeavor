workspace "Endeavor"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Endeavor/vendor/GLFW/include"

include "Endeavor/vendor/GLFW"

project "Endeavor"
	location "Endeavor"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "Endeavor/src/hzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"ED_PLATFORM_WINDOWS",
			"ED_BUILD_DLL"
		}
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "ED_DEBUG"
			buildoptions "/MDd;/utf-8"
			symbols "On"

		filter "configurations:Release"
			defines "ED_RELEASE"
			buildoptions "/MD;/utf-8"
			optimize "On"

		filter "configurations:Dist"
			defines "ED_DIST"
			buildoptions "/MD;/utf-8"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Endeavor/vendor/spdlog/include",
		"Endeavor/src"
	}

	links
	{
		"Endeavor"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ED_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "ED_DEBUG"
			buildoptions "/MDd;/utf-8"
			symbols "On"

		filter "configurations:Release"
			defines "ED_RELEASE"
			buildoptions "/MD;/utf-8"
			optimize "On"

		filter "configurations:Dist"
			defines "ED_DIST"
			buildoptions "/MD;/utf-8"
			optimize "On"