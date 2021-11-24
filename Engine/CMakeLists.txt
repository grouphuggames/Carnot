cmake_minimum_required(VERSION 3.7)
project(CarnotEngine VERSION 0.1.0)

set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)

add_compile_options("/std:c++17")
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

file(GLOB_RECURSE headers RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.h")
file(GLOB_RECURSE sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_library(Engine SHARED ${headers} ${sources})
target_include_directories(Engine PUBLIC ${CMAKE_SOURCE_DIR}/deps/glfw-3.3.5/include ${CMAKE_SOURCE_DIR}/deps/glew-2.1.0/include ${CMAKE_SOURCE_DIR}/deps/FMOD\ Studio\ API\ Windows/api/core/inc)
target_compile_definitions(Engine PRIVATE CARNOT_PLATFORM_WINDOWS CARNOT_BUILD_DLL)
target_link_libraries(Engine OpenGL::GL ${CMAKE_SOURCE_DIR}/deps/glew-2.1.0/lib/Release/x64/glew32s.lib ${CMAKE_SOURCE_DIR}/deps/FMOD\ Studio\ API\ Windows/api/core/lib/x64/fmod_vc.lib)
add_custom_command(TARGET Engine POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/deps/FMOD\ Studio\ API\ Windows/api/core/lib/x64/fmod.dll $<TARGET_FILE_DIR:Engine>)