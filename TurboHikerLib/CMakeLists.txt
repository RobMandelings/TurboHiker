project(TurboHikerLib)

set(SRC
        src/turboHiker/Game.cpp
        src/turboHiker/utils/constants.h src/turboHiker/utils/Clock.cpp src/turboHiker/utils/Clock.h src/turboHiker/utils/NonCopyable.cpp src/turboHiker/utils/NonCopyable.h src/turboHiker/World.cpp src/turboHiker/World.h src/turboHiker/gameObjects/SceneNode.cpp src/turboHiker/gameObjects/SceneNode.h src/turboHiker/abstractVisuals/VisualComponent.h src/turboHiker/utils/maths/Transform.cpp src/turboHiker/utils/maths/Transform.h src/turboHiker/utils/maths/Vector2d.cpp src/turboHiker/utils/maths/Vector2d.h src/turboHiker/interfaces/Updatable.h src/turboHiker/interfaces/Drawable.h src/turboHiker/Removable.h src/turboHiker/Removable.cpp src/turboHiker/abstractVisuals/EmptyVisualComponent.h src/turboHiker/gameObjects/EntityFactory.cpp src/turboHiker/gameObjects/EntityFactory.h src/turboHiker/gameObjects/Entity.cpp src/turboHiker/gameObjects/Entity.h src/turboHiker/ecs/systems/RenderSystem.cpp src/turboHiker/ecs/systems/RenderSystem.h src/turboHiker/ecs/components/Model.cpp src/turboHiker/ecs/components/Model.h src/turboHiker/ecs/systems/PhysicsSystem.cpp src/turboHiker/ecs/systems/PhysicsSystem.h src/turboHiker/ecs/components/WorldPosition.cpp src/turboHiker/ecs/components/WorldPosition.h src/turboHiker/ecs/components/physics/BoundingBox.cpp src/turboHiker/ecs/components/physics/BoundingBox.h)

add_library(TurboHikerLib ${SRC})

include_directories(
        src/turboHiker/
        src/turboHiker/utils/
        src/turboHiker/interfaces/
        src/turboHiker/abstractVisuals/
        src/turboHiker/gameObjects/
        src/turboHiker/utils/maths/
        src/turboHiker/ecs/
        src/turboHiker/ecs/systems/
        src/turboHiker/ecs/components/
        src/turboHiker/ecs/components/physics/
)

target_include_directories(TurboHikerLib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/)

message("Installing TurboHikerLib to target " ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS TurboHikerLib DESTINATION ${PROJECT_SOURCE_DIR}/bin)