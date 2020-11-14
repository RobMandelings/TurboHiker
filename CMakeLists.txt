project(LibTurboHiker)

set(SRC
        src/lib.cpp
        src/lib.h)

include_directories(
        src/
        utils/)

add_library(LibTurboHiker ${SRC})
message("Installing LibTurboHiker to target " ${PROJECT_SOURCE_DIR}/bin)
message("Something")
install(TARGETS LibTurboHiker DESTINATION ${PROJECT_SOURCE_DIR}/bin)