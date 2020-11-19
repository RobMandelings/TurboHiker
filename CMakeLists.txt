cmake_minimum_required(VERSION 3.10)
project(TurboHiker VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)

# Add subdirectories: 'subprojects' of this project. One is the library, one is the SFML implementation
add_subdirectory(TurboHikerLib/)
add_subdirectory(TurboHikerSFML/)