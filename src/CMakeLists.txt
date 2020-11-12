set(SRC
        main.cpp
        utils/constants.h)

include_directories(utils/)

add_executable(TurboHiker ${SRC})
install(TARGETS TurboHiker DESTINATION ${PROJECT_SOURCE_DIR}/bin)