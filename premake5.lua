
-- Workspace: Qubit.sln/.other
-- ---------------------------
workspace "Qubit"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Distribution"
	}

	startproject "Sandbox"

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	include "vendor/glfw"

-- Project: Qubit.lib
-- ------------------
	project "Qubit"
		location "Qubit"
		kind "StaticLib"
		language "c++"

		targetdir ("bin/" .. outputdir .. "%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "%{prj.name}")

		pchheader "QbtPch.h"
		pchsource "%{prj.name}/src/QbtPch.cpp"

		files {
			"%{prj.name}/src/**.cpp",
			"%{prj.name}/src/**.h"
		}

		includedirs {
			"%{prj.name}/src",
			"vendor/glfw/include/GLFW"
		}
		
		links {
			"GLFW"
		}

		filter "system:windows"
			cppdialect "c++17"
			staticruntime "on"
			systemversion "latest"

		filter "configurations:Debug"
			defines "QBT_DEBUG_BUILD"
			symbols "on"

		filter "configurations:Release"
			defines "QBT_RELEASE_BUILD"
			optimize "on"

		filter "configurations:Distribution"
			defines "QBT_DIST_BUILD"
			optimize "on"

-- Project: Sandbox.exe
-- --------------------
	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "c++"

		targetdir ("bin/" .. outputdir .. "%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "%{prj.name}")

		files {
			"%{prj.name}/src/**.cpp",
			"%{prj.name}/src/**.h"
		}

		includedirs {
			"Qubit/src",
			"vendor/glfw/include/GLFW"
		}

		links {
			"Qubit",
			"GLFW"
		}

		filter "system:windows"
			cppdialect "c++17"
			staticruntime "on"
			systemversion "latest"

		filter "configurations:Debug"
			defines "QBT_DEBUG_BUILD"
			symbols "on"

		filter "configurations:Release"
			defines "QBT_RELEASE_BUILD"
			optimize "on"

		filter "configurations:Distribution"
			defines "QBT_DIST_BUILD"
			optimize "on"