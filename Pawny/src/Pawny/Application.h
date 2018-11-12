#pragma once

#include "Core.h"

namespace Pawny {

	class PAWNY_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	};

	// Should be defined on the CLIENT side!
	Application* CreateApplication(); 
}

