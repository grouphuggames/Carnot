#include "Application.h"


namespace Engine
{
  Application::Application()
  {}

  Application::~Application()
  {}
  
  void Application::Run()
  {
#ifdef ENGINE_PLATFORM_WINDOWS
    MSG msg;
    ZeroMemory(&msg, sizeof(MSG));

    while (running)
    {
      if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
      {
        if (msg.message == WM_QUIT)
        {
          break;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
      }

      SwapBuffers(GetDC(hwnd));
    }
#else

#endif
  }
}
