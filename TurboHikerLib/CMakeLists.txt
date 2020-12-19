project(TurboHikerLib)

set(SRC
        src/turboHiker/Game.cpp
        src/turboHiker/utils/constants.h src/turboHiker/utils/Clock.cpp src/turboHiker/utils/Clock.h src/turboHiker/utils/NonCopyable.cpp src/turboHiker/utils/NonCopyable.h)

add_library(TurboHikerLib ${SRC})

include_directories(
        src/turboHiker/
        src/turboHiker/utils/
)

target_include_directories(TurboHikerLib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/)

message("Installing TurboHikerLib to target " ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS TurboHikerLib DESTINATION ${PROJECT_SOURCE_DIR}/bin)