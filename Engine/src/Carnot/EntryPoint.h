#pragma once
#include "Core.h"


extern Carnot::Application* Carnot::CreateApplication();

s32 main()
{
  Carnot::Application* application = Carnot::CreateApplication();

  application->Run();
  delete application;

  return 0;
}
