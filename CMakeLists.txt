cmake_minimum_required(VERSION 3.20)
project(raylib-games)

add_subdirectory(lib/raylib)
include_directories(lib/raylib/src)
add_executable(game src/main.cpp)
target_link_libraries(game raylib)