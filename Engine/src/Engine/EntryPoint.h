#pragma once
#include "Core.h"
#include "Log.h"
#include "Window.h"


#ifdef ENGINE_PLATFORM_WINDOWS

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

#endif
