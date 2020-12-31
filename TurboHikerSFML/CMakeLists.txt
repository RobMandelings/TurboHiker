SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_CXX_STANDARD 17)

# For the libraries, its important to mention all subdirectories in which the .libs are directly located, not in another subfolder.
# For the include directories, this is not necessary
# So what does CMAKE_PREFIX_PATH do?
#Specifies a path which will be used by the FIND_XXX() commands. It contains the “base” directories, the FIND_XXX() commands append appropriate subdirectories to the base directories. So FIND_PROGRAM() adds /bin to each of the directories in the path, FIND_LIBRARY() appends /lib to each of the directories, and FIND_PATH() and FIND_FILE() append /include .
#By default it is empty, it is intended to be set by the project.
#See also CMAKE_SYSTEM_PREFIX_PATH, CMAKE_INCLUDE_PATH, CMAKE_LIBRARY_PATH, CMAKE_PROGRAM_PATH.

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/lib/SFML")

#list(APPEND CMAKE_INCLUDE_PATH "${CMAKE_INCLUDE_PATH}/include/SFML/")
#list(APPEND CMAKE_LIBRARY_PATH "${CMAKE_SOURCE_DIR}/lib/SFML")

# TODO make this optional. Depending on the system you want to startRunning it on, you might want to link to SFML using shared libraries instead of static
set(SFML_STATIC_LIBRARIES TRUE)
# Order does matter
FIND_PACKAGE(SFML 2.4 COMPONENTS graphics window system REQUIRED)

message(STATUS "${SFML_DEPENDENCIES}")

message(STATUS ${SFML_INCLUDE_DIR})
message(STATUS ${SFML_LIBRARIES})

set(SRC
        src/main.cpp
        src/utils/constants.h
        src/SFMLGame.cpp
        src/SFMLGame.h
        ../TurboHikerLib/src/turboHiker/view/Transformation.cpp
        ../TurboHikerLib/src/turboHiker/view/Transformation.h
        src/interfaces/DrawableRenderer.h
        src/EntityFactorySFML.cpp
        src/EntityFactorySFML.h
        src/visualisation/RenderComponentSFML.h
        src/visualisation/SpriteRenderComponent.cpp
        src/visualisation/SpriteRenderComponent.h
        src/visualisation/RenderComponentSFML.cpp
        src/visualisation/ShapeRenderComponent.cpp
        src/visualisation/ShapeRenderComponent.h
        src/inputhandling/Player.cpp
        src/inputhandling/Player.h src/visualisation/MyRenderWindow.cpp src/visualisation/MyRenderWindow.h ../TurboHikerLib/src/turboHiker/view/WorldView.cpp ../TurboHikerLib/src/turboHiker/view/WorldView.h ../TurboHikerLib/src/turboHiker/view/WindowSize.cpp ../TurboHikerLib/src/turboHiker/view/WindowSize.h src/visualisation/Color.cpp src/visualisation/Color.h)

include_directories(
        ${SFML_INCLUDE_DIR}
        src/
        src/utils/
        src/interfaces/
        src/visualComponents/
        src/visualisation/
        src/inputhandling/
)

add_executable(TurboHikerSFML ${SRC})

message(STATUS ${SFML_LIBRARIES} "Bambambam")

# PRIVATE: All the include directories following PRIVATE will be used for the current target only, i.e., appending the directories to INCLUDE_DIRECTORIES.
target_link_libraries(TurboHikerSFML PRIVATE TurboHikerLib ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

message("Installing TurboHikerSFML to target " ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS TurboHikerSFML DESTINATION ${PROJECT_SOURCE_DIR}/bin)