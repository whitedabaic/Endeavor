#pragma once

#ifdef ED_PLATFORM_WINDOWS

extern Endeavor::Application* Endeavor::CreateApplication();

int main(int argc, char** argv)
{
	Endeavor::Log::Init();
	ED_CORE_WARN("Initialized Log!");
	int a = 5;
	ED_INFO("Hello! Var={0}", a);

	auto app = Endeavor::CreateApplication();
	app->Run();
	delete app;
}

#endif