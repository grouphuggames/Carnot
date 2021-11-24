cmake_minimum_required(VERSION 3.7)
project(CarnotEditor VERSION 0.1.0)

set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)

add_compile_options("/std:c++17")
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

file(GLOB_RECURSE headers RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.h")
file(GLOB_RECURSE sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_executable(CarnotEditor ${headers} ${sources})
target_link_libraries(CarnotEditor Engine)
target_compile_definitions(CarnotEditor PRIVATE CARNOT_PLATFORM_WINDOWS)
target_include_directories(CarnotEditor PUBLIC "${CMAKE_SOURCE_DIR}/Engine/src")
add_custom_command(TARGET CarnotEditor POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Engine> $<TARGET_FILE_DIR:CarnotEditor>)
add_custom_command(TARGET CarnotEditor POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/deps/FMOD\ Studio\ API\ Windows/api/core/lib/x64/fmod.dll $<TARGET_FILE_DIR:CarnotEditor>)