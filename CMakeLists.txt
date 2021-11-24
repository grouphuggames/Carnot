cmake_minimum_required(VERSION 3.7)
project(CarnotEngine VERSION 0.1.0)

add_subdirectory(deps/glfw-3.3.5)

add_subdirectory(Engine)
add_subdirectory(Editor)
add_subdirectory(TestGame)