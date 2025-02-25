include "vendor/premake/premake_customization/solution_items.lua"

workspace "Endeavor"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Endeavor/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Endeavor/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Endeavor/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Endeavor/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Endeavor/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Endeavor/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Endeavor/vendor/yaml-cpp/include"

group "Dependencies"
	include "vendor/premake"
	include "Endeavor/vendor/GLFW"
	include "Endeavor/vendor/Glad"
	include "Endeavor/vendor/imgui"
	include "Endeavor/vendor/yaml-cpp"
group ""

include "Endeavor"
include "Sandbox"
include "Endeavor-Editor"
