#pragma once

#ifdef PW_PLATFORM_WINDOWS

extern Pawny::Application* Pawny::CreateApplication();

int main(int argc, char** argv)
{
	Pawny::Log::Init();
	PW_INFO("Let it be!");

	PW_ERROR("That is an error!");

	auto app = Pawny::CreateApplication();
	app->Run();
	delete app;
}

#endif