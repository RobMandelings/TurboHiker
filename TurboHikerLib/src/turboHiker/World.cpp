//
// Created by RobMa on 19/12/2020.
//

#include "World.h"
#include <cassert>

#include "PhysicsComponent.h"
#include "InputComponent.h"
#include "RenderComponent.h"
#include "CollisionComponent.h"

turboHiker::World::World() {
        buildWorld();
}

void turboHiker::World::update(Updatable::seconds dt) {
        mSceneGraph->update(dt);
}

void turboHiker::World::draw() const {

}

void turboHiker::World::buildWorld() {
        // Pre-condition
        assert(mSceneGraph == nullptr && "The world is already built!");


        // Post-condition
        assert(mSceneGraph != nullptr);
}
