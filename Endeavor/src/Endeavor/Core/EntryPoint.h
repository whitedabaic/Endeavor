#pragma once

#include "Endeavor/Core/Base.h"

#ifdef ED_PLATFORM_WINDOWS

extern Endeavor::Application* Endeavor::CreateApplication();

int main(int argc, char** argv)
{
	Endeavor::Log::Init();

	ED_PROFILE_BEGIN_SESSION("Startup", "EndeavorProfile-Startup.json");
	auto app = Endeavor::CreateApplication();
	ED_PROFILE_END_SESSION();

	ED_PROFILE_BEGIN_SESSION("Runtime", "EndeavorProfile-Runtime.json");
	app->Run();
	ED_PROFILE_END_SESSION();

	ED_PROFILE_BEGIN_SESSION("Shutdown", "EndeavorProfile-Shutdown.json");
	delete app;
	ED_PROFILE_END_SESSION();
}

#endif