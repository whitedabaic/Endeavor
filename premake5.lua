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

group "Dependencies"
	include "Endeavor/vendor/GLFW"
	include "Endeavor/vendor/Glad"
	include "Endeavor/vendor/imgui"

group ""

project "Endeavor"
	location "Endeavor"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "edpch.h"
	pchsource "Endeavor/src/edpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.Imgui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"Imgui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		defines
		{
			"ED_PLATFORM_WINDOWS",
			"ED_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

		filter "configurations:Debug"
			defines "ED_DEBUG"
			runtime "Debug"
			buildoptions "/utf-8"
			symbols "On"

		filter "configurations:Release"
			defines "ED_RELEASE"
			runtime "Release"
			buildoptions "/utf-8"
			optimize "On"

		filter "configurations:Dist"
			defines "ED_DIST"
			runtime "Release"
			buildoptions "/utf-8"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"ED_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "ED_DEBUG"
			runtime "Debug"
			buildoptions "/utf-8"
			symbols "On"

		filter "configurations:Release"
			defines "ED_RELEASE"
			runtime "Release"
			buildoptions "/utf-8"
			optimize "On"

		filter "configurations:Dist"
			defines "ED_DIST"
			runtime "Release"
			buildoptions "/utf-8"
			optimize "On"