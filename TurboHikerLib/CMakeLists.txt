project(TurboHikerLib)

set(SRC
        src/turboHiker/Game.cpp
        src/turboHiker/utils/constants.h
        src/turboHiker/utils/Clock.cpp
        src/turboHiker/utils/Clock.h
        src/turboHiker/utils/NonCopyable.cpp
        src/turboHiker/utils/NonCopyable.h
        src/turboHiker/World.cpp
        src/turboHiker/World.h
        src/turboHiker/gameObjects/Entity.cpp
        src/turboHiker/gameObjects/Entity.h
        src/turboHiker/utils/maths/Transform.cpp
        src/turboHiker/utils/maths/Transform.h
        src/turboHiker/utils/maths/Vector2d.cpp
        src/turboHiker/utils/maths/Vector2d.h
        src/turboHiker/interfaces/Updatable.h
        src/turboHiker/interfaces/Renderable.h
        src/turboHiker/Removable.h
        src/turboHiker/Removable.cpp
        src/turboHiker/gameObjects/EntityFactory.h
        src/turboHiker/gameObjects/components/RenderComponent.cpp
        src/turboHiker/gameObjects/components/RenderComponent.h
        src/turboHiker/gameObjects/components/physics/PhysicsComponent.cpp
        src/turboHiker/gameObjects/components/physics/PhysicsComponent.h
        src/turboHiker/gameObjects/components/modules/WorldLocation.cpp
        src/turboHiker/gameObjects/components/modules/WorldLocation.h
        src/turboHiker/gameObjects/components/modules/BoundingBox.cpp
        src/turboHiker/gameObjects/components/modules/BoundingBox.h
        src/turboHiker/gameObjects/components/InputComponent.cpp
        src/turboHiker/gameObjects/components/InputComponent.h
        src/turboHiker/gameObjects/components/physics/MovingPhysicsComponent.cpp
        src/turboHiker/gameObjects/components/physics/MovingPhysicsComponent.h
        src/turboHiker/gameObjects/components/EmptyRenderComponent.cpp
        src/turboHiker/gameObjects/components/EmptyRenderComponent.h
        src/turboHiker/gameObjects/components/physics/CollisionComponent.cpp
        src/turboHiker/gameObjects/components/physics/CollisionComponent.h
        src/turboHiker/gameObjects/Hiker.cpp
        src/turboHiker/gameObjects/Hiker.h)

add_library(TurboHikerLib ${SRC})

set(INCLUDE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/utils/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/interfaces/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/gameObjects/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/utils/maths/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/ecs/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/gameObjects/components/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/gameObjects/components/modules/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/gameObjects/components/physics/)

target_include_directories(TurboHikerLib PUBLIC
        ${INCLUDE})

message("Installing TurboHikerLib to target " ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS TurboHikerLib DESTINATION ${PROJECT_SOURCE_DIR}/bin)