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
        src/turboHiker/entities/SceneNode.cpp
        src/turboHiker/entities/SceneNode.h
        src/turboHiker/utils/maths/Transform.cpp
        src/turboHiker/utils/maths/Transform.h
        src/turboHiker/utils/maths/Vector2d.cpp
        src/turboHiker/utils/maths/Vector2d.h
        src/turboHiker/interfaces/Updatable.h
        src/turboHiker/interfaces/Renderable.h
        src/turboHiker/Removable.h
        src/turboHiker/Removable.cpp
        src/turboHiker/entities/EntityFactory.h
        src/turboHiker/entities/components/RenderComponent.h
        src/turboHiker/entities/components/physics/PhysicsComponent.cpp
        src/turboHiker/entities/components/physics/PhysicsComponent.h
        src/turboHiker/entities/components/modules/WorldLocation.cpp
        src/turboHiker/entities/components/modules/WorldLocation.h
        src/turboHiker/entities/components/modules/BoundingBox.cpp
        src/turboHiker/entities/components/modules/BoundingBox.h
        src/turboHiker/entities/components/InputComponent.cpp
        src/turboHiker/entities/components/InputComponent.h
        src/turboHiker/entities/components/physics/MovingPhysicsComponent.cpp
        src/turboHiker/entities/components/physics/MovingPhysicsComponent.h
        src/turboHiker/entities/components/physics/CollisionComponent.cpp
        src/turboHiker/entities/components/physics/CollisionComponent.h
        src/turboHiker/entities/Hiker.cpp
        src/turboHiker/entities/Hiker.h
        src/turboHiker/entities/MovableEntity.cpp
        src/turboHiker/entities/MovableEntity.h
        src/turboHiker/Category.h
        src/turboHiker/Command.cpp
        src/turboHiker/Command.h
        src/turboHiker/CommandQueue.h
        src/turboHiker/CommandQueue.cpp)

add_library(TurboHikerLib ${SRC})

set(INCLUDE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/utils/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/interfaces/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/entities/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/utils/maths/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/ecs/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/entities/components/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/entities/components/modules/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/entities/components/physics/)

target_include_directories(TurboHikerLib PUBLIC
        ${INCLUDE})

message("Installing TurboHikerLib to target " ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS TurboHikerLib DESTINATION ${PROJECT_SOURCE_DIR}/bin)