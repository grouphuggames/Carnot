cmake_minimum_required(VERSION 3.7)
project(TestGame VERSION 0.1.0)

add_compile_options("/std:c++17")
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

file(GLOB_RECURSE headers RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.h")
file(GLOB_RECURSE sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_executable(CarnotGame ${headers} ${sources})
target_link_libraries(CarnotGame Engine)
target_compile_definitions(CarnotGame PRIVATE CARNOT_PLATFORM_WINDOWS)
target_include_directories(CarnotGame PUBLIC "${CMAKE_SOURCE_DIR}/Engine/src")
add_custom_command(TARGET CarnotGame POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Engine> $<TARGET_FILE_DIR:CarnotGame>)