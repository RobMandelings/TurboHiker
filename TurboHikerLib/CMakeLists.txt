project(TurboHikerLib)

set(SRC
        src/turboHikerLib/Game.cpp
        src/turboHikerLib/utils/constants.h src/turboHikerLib/utils/Clock.cpp src/turboHikerLib/utils/Clock.h src/turboHikerLib/utils/NonCopyable.cpp src/turboHikerLib/utils/NonCopyable.h)

add_library(TurboHikerLib ${SRC})

include_directories(
        src/turboHikerLib/
        src/turboHikerLib/utils/
)

target_include_directories(TurboHikerLib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/)

message("Installing TurboHikerLib to target " ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS TurboHikerLib DESTINATION ${PROJECT_SOURCE_DIR}/bin)