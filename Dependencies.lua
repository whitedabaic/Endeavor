
-- Endeavor Dependencies

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/Endeavor/vendor/stb_image"
IncludeDir["yaml_cpp"] = "%{wks.location}/Endeavor/vendor/yaml-cpp/include"
IncludeDir["Box2D"] = "%{wks.location}/Endeavor/vendor/Box2D/include"
IncludeDir["GLFW"] = "%{wks.location}/Endeavor/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Endeavor/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Endeavor/vendor/ImGui"
IncludeDir["ImGuizmo"] = "%{wks.location}/Endeavor/vendor/ImGuizmo"
IncludeDir["glm"] = "%{wks.location}/Endeavor/vendor/glm"
IncludeDir["entt"] = "%{wks.location}/Endeavor/vendor/entt/include"
IncludeDir["mono"] = "%{wks.location}/Endeavor/vendor/mono/include"
IncludeDir["shaderc"] = "%{wks.location}/Endeavor/vendor/VulkanSDK/Include/shaderc"
IncludeDir["SPIRV_Cross"] = "%{wks.location}/Endeavor/vendor/VulkanSDK/Include/spirv_cross"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

LibraryDir = {}

LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"
LibraryDir["mono"] = "%{wks.location}/Endeavor/vendor/mono/lib/%{cfg.buildcfg}"

Library = {}
Library["mono"] = "%{LibraryDir.mono}/libmono-static-sgen.lib"

Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"

Library["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK}/shaderc_sharedd.lib"
Library["SPIRV_Cross_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsld.lib"
Library["SPIRV_Tools_Debug"] = "%{LibraryDir.VulkanSDK}/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Library["SPIRV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"

-- Windows
Library["WinSock"] = "Ws2_32.lib"
Library["WinMM"] = "Winmm.lib"
Library["WinVersion"] = "Version.lib"
Library["BCrypt"] = "Bcrypt.lib"
