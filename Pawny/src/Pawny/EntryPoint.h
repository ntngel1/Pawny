#pragma once

#ifdef PW_PLATFORM_WINDOWS

extern Pawny::Application* Pawny::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Pawny::CreateApplication();
	app->Run();
	delete app;
}

#endif