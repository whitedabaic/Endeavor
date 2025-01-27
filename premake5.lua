workspace "Endeavor"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Endeavor"
	location "Endeavor"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"
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
			symbols "On"

		filter "configurations:Release"
			defines "ED_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "ED_DIST"
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

	links
	{
		"Endeavor"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"ED_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "ED_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "ED_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "ED_DIST"
			optimize "On"