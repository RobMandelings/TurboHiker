cmake_minimum_required(VERSION 3.10)
project(TurboHiker)
set(CMAKE_CXX_STANDARD 17)

# TODO can you make it so that you should only include_directories in TurboHikerLib and it becomes available to TurboHikerSFML as well?
include_directories(TurboHikerLib/src/)

add_subdirectory(TurboHikerLib/)
add_subdirectory(TurboHikerSFML/)