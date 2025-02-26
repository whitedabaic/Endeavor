project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Endeavor/vendor/spdlog/include",
		"%{wks.location}/Endeavor/src",
		"%{wks.location}/Endeavor/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Endeavor"
	}

	filter "system:windows"
		systemversion "latest"

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