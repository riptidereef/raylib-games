cmake_minimum_required(VERSION 3.20)
project(raylib-games)

add_subdirectory(lib/raylib)
include_directories(lib/raylib/src)

add_subdirectory(lib/tmxlite/tmxlite)
include_directories(lib/tmxlite/tmxlite/src)

file(GLOB SRC_FILES src/*.cpp src/*.h)

add_executable(game ${SRC_FILES})

target_link_libraries(game raylib tmxlite)
