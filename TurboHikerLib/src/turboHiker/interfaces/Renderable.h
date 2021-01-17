//
// Created by RobMa on 20/12/2020.
//

#ifndef TURBOHIKER_RENDERABLE_H
#define TURBOHIKER_RENDERABLE_H

namespace turboHiker {

/**
 * Implement this if you want to be able to render your object
 */
class Renderable
{

public:

        /**
         * Pure virtual method that needs to have a concrete implementation
         */
        virtual void render() const = 0;
};
} // namespace turboHiker

#endif // TURBOHIKER_RENDERABLE_H
