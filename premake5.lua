include "vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

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

group "Dependencies"
	include "vendor/premake"
	include "Endeavor/vendor/Box2D"
	include "Endeavor/vendor/GLFW"
	include "Endeavor/vendor/Glad"
	include "Endeavor/vendor/imgui"
	include "Endeavor/vendor/yaml-cpp"
group ""

include "Endeavor"
include "Sandbox"
include "Endeavor-Editor"
