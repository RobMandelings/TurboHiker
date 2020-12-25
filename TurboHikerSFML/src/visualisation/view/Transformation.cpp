//
// Created by RobMa on 19/12/2020.
//

#include "Transformation.h"

#include <cassert>

using namespace turboHikerSFML;

Transformation::Transformation() : mWorldView(nullptr) {}

const Transformation& Transformation::get()
{
        std::lock_guard<std::mutex> lock(mMutex);
        static Transformation instance;

        return instance;
}

void Transformation::initWorldView(const WorldView& worldView)
{
        assert(mWorldView == nullptr && "WorldView is already initialized");
        mWorldView = std::make_unique<WorldView>(worldView);
}
WorldView& Transformation::getWorldView() const
{
        assert(mWorldView != nullptr && "WorldView is not yet initialized!");
        return *mWorldView;
}
