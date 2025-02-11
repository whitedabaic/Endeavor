workspace "Endeavor"
	architecture "x64"
	startproject "Sandbox"

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
IncludeDir["Glad"] = "Endeavor/vendor/Glad/include"
IncludeDir["Imgui"] = "Endeavor/vendor/imgui"
IncludeDir["glm"] = "Endeavor/vendor/glm"
IncludeDir["stb_image"] = "Endeavor/vendor/stb_image"

group "Dependencies"
	include "Endeavor/vendor/GLFW"
	include "Endeavor/vendor/Glad"
	include "Endeavor/vendor/imgui"

group ""

project "Endeavor"
	location "Endeavor"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "edpch.h"
	pchsource "Endeavor/src/edpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.Imgui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links
	{
		"GLFW",
		"Glad",
		"Imgui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"ED_PLATFORM_WINDOWS",
			"ED_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		filter "configurations:Debug"
			defines "ED_DEBUG"
			runtime "Debug"
			buildoptions "/utf-8"
			symbols "on"

		filter "configurations:Release"
			defines "ED_RELEASE"
			runtime "Release"
			buildoptions "/utf-8"
			optimize "on"

		filter "configurations:Dist"
			defines "ED_DIST"
			runtime "Release"
			buildoptions "/utf-8"
			optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"Endeavor/src",
		"Endeavor/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Endeavor"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"ED_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "ED_DEBUG"
			runtime "Debug"
			buildoptions "/utf-8"
			symbols "on"

		filter "configurations:Release"
			defines "ED_RELEASE"
			runtime "Release"
			buildoptions "/utf-8"
			optimize "on"

		filter "configurations:Dist"
			defines "ED_DIST"
			runtime "Release"
			buildoptions "/utf-8"
			optimize "on"