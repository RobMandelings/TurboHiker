project(TurboHikerLib)

set(CMAKE_CXX_STANDARD 17)

set(SRC
        src/turboHiker/Game.cpp
        src/turboHiker/utils/Stopwatch.cpp
        src/turboHiker/utils/Stopwatch.h
        src/turboHiker/world/World.cpp
        src/turboHiker/world/World.h
        src/turboHiker/scenenodes/SceneNode.cpp
        src/turboHiker/scenenodes/SceneNode.h
        src/turboHiker/utils/maths/Vector2d.cpp
        src/turboHiker/utils/maths/Vector2d.h
        src/turboHiker/interfaces/Updatable.h
        src/turboHiker/interfaces/Renderable.h
        src/turboHiker/interfaces/Removable.h
        src/turboHiker/interfaces/Removable.cpp
        src/turboHiker/scenenodes/SceneNodeFactory.h
        src/turboHiker/scenenodes/components/Renderer.h
        src/turboHiker/scenenodes/components/BoundingBox.cpp
        src/turboHiker/scenenodes/components/BoundingBox.h
        src/turboHiker/scenenodes/entities/Hiker.cpp
        src/turboHiker/scenenodes/entities/Hiker.h
        src/turboHiker/scenenodes/entities/Entity.cpp
        src/turboHiker/scenenodes/entities/Entity.h
        src/turboHiker/commands/Command.cpp
        src/turboHiker/commands/Command.h
        src/turboHiker/commands/CommandQueue.h
        src/turboHiker/commands/CommandQueue.cpp
        src/turboHiker/world/SceneGraph.cpp
        src/turboHiker/world/SceneGraph.h
        src/turboHiker/utils/Random.cpp
        src/turboHiker/utils/Random.h
        src/turboHiker/interfaces/Commandable.h
        src/turboHiker/scenenodes/entities/PlayerHiker.cpp
        src/turboHiker/scenenodes/entities/PlayerHiker.h
        src/turboHiker/scenenodes/Finish.h
        src/turboHiker/scenenodes/Finish.cpp
        src/turboHiker/interfaces/EventObserver.h
        src/turboHiker/scoring/Score.cpp
        src/turboHiker/scoring/Score.h
        src/turboHiker/interfaces/Observable.cpp
        src/turboHiker/interfaces/Observable.h src/turboHiker/scoring/HighScoreContainer.cpp src/turboHiker/scoring/HighScoreContainer.h src/turboHiker/scenenodes/entities/RunningHiker.cpp src/turboHiker/scenenodes/entities/RunningHiker.h src/turboHiker/GameCategory.h src/turboHiker/HikeStatus.h src/turboHiker/scenenodes/entities/StaticHiker.cpp src/turboHiker/scenenodes/entities/StaticHiker.h)

add_library(TurboHikerLib ${SRC})

set(INCLUDE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/view/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/utils/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/utils/maths/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/interfaces/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/scenenodes/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/scenenodes/entities/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/scenenodes/components/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/commands/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/stats/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/world/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/turboHiker/scoring/)

target_include_directories(TurboHikerLib PUBLIC
        ${INCLUDE})

message("Installing TurboHikerLib to target " ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS TurboHikerLib DESTINATION ${PROJECT_SOURCE_DIR}/bin)