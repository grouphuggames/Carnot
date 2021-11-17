#pragma once
#include "Core.h"


#ifdef ENGINE_PLATFORM_WINDOWS

#include "Windows/Log.h"
#include "Windows/Window.h"

extern Engine::Application* Engine::CreateApplication();

s32 WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, s32 nCmdShow)
{
  Engine::CreateWIN32DebugConsole();
  Engine::Application* application = Engine::CreateApplication();
  Engine::CreateWIN32Window(hInstance, nCmdShow);
  application->Run();
  delete application;
  
  return 0;
}

#else

s32 main()
{
  return 0;
}

#endif
