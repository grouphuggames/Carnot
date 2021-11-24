#include "Application.h"


namespace Carnot
{
  Application::Application()
  {}

  Application::~Application()
  {}
  
  void Application::Run()
  {
    if (!glewInit())
    {
      return;
    }

    if (FMOD::System_Create(&audio_system) != FMOD_OK)
    {
      return;
    }

    while(true);
  }
}
