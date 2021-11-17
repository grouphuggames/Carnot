#pragma once

#include "Engine/Application.h"
#include "Engine/EntryPoint.h"

#ifdef ENGINE_PLATFORM_WINDOWS
  #include "Engine/Windows/Log.h"
  #include "Engine/Windows/Window.h"
#else
  #include "Engine/Linux/Log.h"
  #include "Engine/Linux/Window.h"
#endif