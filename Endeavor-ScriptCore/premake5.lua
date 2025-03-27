project "Endeavor-ScriptCore"
	kind "SharedLib"
	language "C#"
	dotnetframework "4.7.2"

	targetdir ("%{wks.location}/Endeavor-Editor/Resources/Scripts")
	objdir ("%{wks.location}/Endeavor-Editor/Resources/Scripts/Intermediates")

	files 
	{
		"Source/**.cs",
		"Properties/**.cs"
	}
	
	filter "configurations:Debug"
		optimize "Off"
		symbols "Default"
		buildoptions "/utf-8"

	filter "configurations:Release"
		optimize "On"
		symbols "Default"
		buildoptions "/utf-8"

	filter "configurations:Dist"
		optimize "Full"
		symbols "Off"
		buildoptions "/utf-8"
