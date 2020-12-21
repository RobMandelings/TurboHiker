project(TurboHikerLib)

set(SRC
        src/turboHiker/Game.cpp
        src/turboHiker/utils/constants.h src/turboHiker/utils/Clock.cpp src/turboHiker/utils/Clock.h src/turboHiker/utils/NonCopyable.cpp src/turboHiker/utils/NonCopyable.h src/turboHiker/World.cpp src/turboHiker/World.h src/turboHiker/gameObjects/GameObject.cpp src/turboHiker/gameObjects/GameObject.h src/turboHiker/abstractVisuals/VisualComponent.h src/turboHiker/utils/maths/Transform.cpp src/turboHiker/utils/maths/Transform.h src/turboHiker/utils/maths/Vector2d.cpp src/turboHiker/utils/maths/Vector2d.h src/turboHiker/interfaces/Updatable.h src/turboHiker/interfaces/Drawable.h src/turboHiker/Removable.h src/turboHiker/Removable.cpp src/turboHiker/abstractVisuals/EmptyVisualComponent.h)

add_library(TurboHikerLib ${SRC})

include_directories(
        src/turboHiker/
        src/turboHiker/utils/
        src/turboHiker/interfaces/
        src/turboHiker/abstractVisuals/
        src/turboHiker/gameObjects/
        src/turboHiker/utils/maths/
)

target_include_directories(TurboHikerLib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/)

message("Installing TurboHikerLib to target " ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS TurboHikerLib DESTINATION ${PROJECT_SOURCE_DIR}/bin)