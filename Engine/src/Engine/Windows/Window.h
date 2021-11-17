#pragma once
#include "Core.h"

namespace Engine
{
  LRESULT CALLBACK ProcessInput(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
  {
    switch (msg)
    {
    case WM_KEYDOWN:
      switch (wParam)
      {
      case 0x1B:
        running = false;
        DestroyWindow(hwnd);
        break;
      }
    default:
      break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
  }
  
  void CreateWIN32Window(HINSTANCE hInstance, s32 nShowCmd)
  {
    LPCTSTR window_name = "ApplicationWindow";
    const char* window_title = "ApplicationWindow";

    s32 window_width = 1280;
    s32 window_height = 720;

    if (fullscreen)
    {
      HMONITOR hmon = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
      MONITORINFO mi = { sizeof(mi) };
      GetMonitorInfo(hmon, &mi);

      s32 width = mi.rcMonitor.right - mi.rcMonitor.left;
      s32 height = mi.rcMonitor.bottom - mi.rcMonitor.top;

      window_width = width;
      window_height = height;
    }

    RECT rect = { 0, 0, window_width, window_height };

    if (!fullscreen)
    {
      DWORD style = WS_OVERLAPPEDWINDOW;
      DWORD ex_style = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
      AdjustWindowRectEx(&rect, style, FALSE, ex_style);
    }

    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wc.lpfnWndProc = ProcessInput;
    wc.cbClsExtra = NULL;
    wc.cbWndExtra = NULL;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = window_name;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    RegisterClassEx(&wc);

    hwnd = CreateWindowEx(NULL, window_name, window_title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, NULL);
    if (!hwnd)
    {
      std::cout << "Error: Could not open window!\n";
    }

    if (fullscreen)
    {
      SetWindowLong(hwnd, GWL_STYLE, 0);
    }

    ShowCursor(!cursor_hidden);
    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);
  }
}
