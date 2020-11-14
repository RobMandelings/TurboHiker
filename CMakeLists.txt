cmake_minimum_required(VERSION 3.10)
project(TurboHiker)
set(CMAKE_CXX_STANDARD 17)

# TODO can you make it so that you should only include_directories in LibTurboHiker and it becomes available to SFMLTurboHiker as well?
include_directories(LibTurboHiker/src/)

add_subdirectory(LibTurboHiker/)
add_subdirectory(SFMLTurboHiker/)