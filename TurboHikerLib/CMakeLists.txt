project(TurboHikerLib)

set(SRC
        src/Game.cpp
        src/utils/constants.h src/utils/Clock.cpp src/utils/Clock.h)

add_library(TurboHikerLib ${SRC})

target_include_directories(TurboHikerLib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/)

message("Installing TurboHikerLib to target " ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS TurboHikerLib DESTINATION ${PROJECT_SOURCE_DIR}/bin)