//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_TRANSFORMATION_H
#define TURBOHIKER_TRANSFORMATION_H

#include "WorldView.h"

#include <mutex>
#include <utility>
#include <memory>

namespace turboHikerSFML {

class Transformation
{

public:

        Transformation(Transformation& other) = delete;

        void operator=(const Transformation&) = delete;

        static const Transformation& get();

        void initWorldView(const WorldView& worldView);

        WorldView& getWorldView() const;

private:

        explicit Transformation();

private:

        static Transformation mInstance;

        static std::mutex mMutex;

        std::unique_ptr<WorldView> mWorldView;

};

std::mutex Transformation::mMutex;


} // namespace turboHikerSFML

#endif // TURBOHIKER_TRANSFORMATION_H
