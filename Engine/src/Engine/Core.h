#pragma once
#include <cstdint>
#include <iostream>


using s32 = int32_t;
using u32 = uint32_t;
using f32  = float;
using f64 = double;

#ifdef ENGINE_PLATFORM_WINDOWS
  #include <Windows.h>

  #ifdef ENGINE_BUILD_DLL
    #define ENGINE_API __declspec(dllexport)
  #else
    #define ENGINE_API __declspec(dllimport)
  #endif
#else
  #error Engine Only Supports Windows!
#endif
