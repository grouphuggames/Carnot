cmake_minimum_required(VERSION 3.7)
project(CarnotEngine VERSION 0.1.0)

add_compile_options("/std:c++17")
add_link_options("/SUBSYSTEM:WINDOWS")
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

file(GLOB_RECURSE headers RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.h")
file(GLOB_RECURSE sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_library(Engine SHARED ${headers} ${sources})
target_compile_definitions(Engine PRIVATE ENGINE_PLATFORM_WINDOWS ENGINE_BUILD_DLL)