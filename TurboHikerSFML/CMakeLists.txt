set(SRC
        src/main.cpp
        src/utils/constants.h)

include_directories(
        src/
        utils/)

add_executable(TurboHikerSFML ${SRC})

target_link_libraries(TurboHikerSFML PRIVATE TurboHikerLib)

message("Installing TurboHikerSFML to target " ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS TurboHikerSFML DESTINATION ${PROJECT_SOURCE_DIR}/bin)