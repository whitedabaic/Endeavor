#pragma once

#ifdef ED_PLATFORM_WINDOWS

extern Endeavor::Application* Endeavor::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Endeavor::CreateApplication();
	app->Run();
	delete app;
}

#endif