#pragma once
#include "Core.h"


namespace Engine
{
  class ENGINE_API Application
  {
  public:
    Application();
    virtual ~Application();
	
	void Run();
  };
  
  Application* CreateApplication();

#ifdef ENGINE_PLATFORM_WINDOWS
  HWND hwnd;
#else
#endif

  bool fullscreen;
  bool running = true;
  bool cursor_hidden;
}
