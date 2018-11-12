#include <Pawny.h>

class Sandbox : public Pawny::Application 
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}


};

Pawny::Application* Pawny::CreateApplication()
{
	return new Sandbox();
}