set(SRC
        src/main.cpp
        src/utils/constants.h)

include_directories(
        src/
        utils/)

add_executable(SFMLTurboHiker ${SRC})

target_link_libraries(SFMLTurboHiker LibTurboHiker)

message("Installing SFMLTurboHiker to target " ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS SFMLTurboHiker DESTINATION ${PROJECT_SOURCE_DIR}/bin)