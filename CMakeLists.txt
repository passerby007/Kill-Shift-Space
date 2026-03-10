cmake_minimum_required(VERSION 3.15)
project(kill-shift-space LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/.output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/.output)

add_executable(kill-shift-space WIN32 kill_shift_space.cpp)
target_link_libraries(kill-shift-space PRIVATE user32)

add_executable(retreat-killer retreat_killer.cpp)
