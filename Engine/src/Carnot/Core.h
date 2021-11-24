#pragma once
#include <cstdint>
#include <iostream>


using s32 = int32_t;
using u32 = uint32_t;
using f32  = float;
using f64 = double;

#ifdef CARNOT_PLATFORM_WINDOWS
  #ifdef CARNOT_BUILD_DLL
    #define CARNOT_API __declspec(dllexport)
  #else
    #define CARNOT_API __declspec(dllimport)
  #endif
#else
  #error Engine Only Supports Windows!
#endif
