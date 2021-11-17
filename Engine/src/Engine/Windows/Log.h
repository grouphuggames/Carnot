#pragma once
#include "Core.h"


namespace Engine
{
  void CreateWIN32DebugConsole()
  {
    LPCTSTR console_name = "Debug Console";
    AllocConsole();
    SetConsoleTitle(console_name);
    freopen("CONOUT$", "w", stdout);
  }
}
