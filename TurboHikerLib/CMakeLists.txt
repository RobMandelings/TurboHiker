project(TurboHikerLib)

set(SRC
        src/turbo_lib/lib.cpp
        src/turbo_lib/lib.h)

add_library(TurboHikerLib ${SRC})

target_include_directories(TurboHikerLib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/)

message("Installing TurboHikerLib to target " ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS TurboHikerLib DESTINATION ${PROJECT_SOURCE_DIR}/bin)