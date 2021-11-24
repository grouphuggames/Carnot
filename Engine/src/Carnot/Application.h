#pragma once
#define GLEW_STATIC

#include "Core.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fmod.hpp>


namespace Carnot
{
  class CARNOT_API Application
  {
  public:
    Application();
    virtual ~Application();
	
	void Run();
  };
  
  Application* CreateApplication();

  bool fullscreen;
  bool running = true;
  char* app_name;
  s32 window_width = 1280;
  s32 window_height = 720;

  GLFWwindow* window;
  FMOD::System* audio_system;
}
