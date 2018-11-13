#pragma once

#ifdef PW_PLATFORM_WINDOWS

extern Pawny::Application* Pawny::CreateApplication();

int main(int argc, char** argv)
{
	Pawny::Log::Init();
	PW_CORE_WARN("WARNING! You should update your DLLs!");
	PW_INFO("Game was started successfully!");

	auto app = Pawny::CreateApplication();
	app->Run();
	delete app;
}

#endif