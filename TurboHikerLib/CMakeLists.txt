project(TurboHikerLib)

set(SRC
        src/turboHiker/Game.cpp
        src/turboHiker/utils/constants.h src/turboHiker/utils/Clock.cpp src/turboHiker/utils/Clock.h src/turboHiker/utils/NonCopyable.cpp src/turboHiker/utils/NonCopyable.h src/turboHiker/World.cpp src/turboHiker/World.h src/turboHiker/gameObjects/Entity.cpp src/turboHiker/gameObjects/Entity.h src/turboHiker/abstractVisuals/VisualComponent.h src/turboHiker/utils/maths/Transform.cpp src/turboHiker/utils/maths/Transform.h src/turboHiker/utils/maths/Vector2d.cpp src/turboHiker/utils/maths/Vector2d.h src/turboHiker/interfaces/Updatable.h src/turboHiker/interfaces/Drawable.h src/turboHiker/Removable.h src/turboHiker/Removable.cpp src/turboHiker/abstractVisuals/EmptyVisualComponent.h src/turboHiker/gameObjects/EntityFactory.h src/turboHiker/ecs/components/RenderComponent.cpp src/turboHiker/ecs/components/RenderComponent.h src/turboHiker/ecs/modules/Model.cpp src/turboHiker/ecs/modules/Model.h src/turboHiker/ecs/components/PhysicsComponent.cpp src/turboHiker/ecs/components/PhysicsComponent.h src/turboHiker/ecs/modules/WorldPosition.cpp src/turboHiker/ecs/modules/WorldPosition.h src/turboHiker/ecs/modules/physics/BoundingBox.cpp src/turboHiker/ecs/modules/physics/BoundingBox.h src/turboHiker/ecs/components/InputComponent.cpp src/turboHiker/ecs/components/InputComponent.h src/turboHiker/ecs/components/MovingPhysicsComponent.cpp src/turboHiker/ecs/components/MovingPhysicsComponent.h)

add_library(TurboHikerLib ${SRC})

include_directories(
        src/turboHiker/
        src/turboHiker/utils/
        src/turboHiker/interfaces/
        src/turboHiker/abstractVisuals/
        src/turboHiker/gameObjects/
        src/turboHiker/utils/maths/
        src/turboHiker/ecs/
        src/turboHiker/ecs/components/
        src/turboHiker/ecs/modules/
        src/turboHiker/ecs/modules/physics/
)

target_include_directories(TurboHikerLib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/)

message("Installing TurboHikerLib to target " ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS TurboHikerLib DESTINATION ${PROJECT_SOURCE_DIR}/bin)