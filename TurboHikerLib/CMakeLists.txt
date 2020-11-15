project(TurboHikerLib)

set(SRC
        src/lib.cpp
        src/lib.h)

include_directories(
        src/
        utils/)

add_library(TurboHikerLib ${SRC})
message("Installing TurboHikerLib to target " ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS TurboHikerLib DESTINATION ${PROJECT_SOURCE_DIR}/bin)