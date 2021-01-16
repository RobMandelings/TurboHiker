//
// Created by Rob Mandelings on 25/12/2020.
//

#pragma once

#include "Vector2d.h"

namespace turboHiker {

/**
 * Class to contain the basic necessities for implementing a view of the world
 */
class WorldView
{

public:

        /**
         *
         * @param width: how wide you can see the world
         * @param height: how high you can see the world
         * @param worldViewCenter: the initial center of the world: you can see width / 2 to the left of the center, width / 2 to the right of the center etc...
         */
        WorldView(double width, double height, const turboHiker::Vector2d& worldViewCenter);

        /**
         * Simple getter
         * @return the current setting of how wide you can see the world
         */
        double getWorldViewWidth() const;

        /**
         * Simple getter
         * @param width: the new width
         */
        void setWidth(double width);

        /**
         * Simple getter
         * @return  the current setting of how high you can see the world
         */
        double getWorldViewHeight() const;

        /**
         * Simple setter
         * @param height: the new height
         */
        void setHeight(double height);

        /**
         * Simple getter
         * @return the current center of view for the world
         */
        const turboHiker::Vector2d& getWorldViewCenter() const;

        /**
         * Simple setter
         * @param worldViewCenter: the new world view center
         */
        void setWorldViewCenter(const turboHiker::Vector2d& worldViewCenter);

private:

        /**
         * The current setting of how wide you can see the world (in world coordinates)
         */
        double mWidth;

        /**
         * The current setting of how high you can see the world (in world coordinates)
         */
        double mHeight;

        /**
         * The current center of the world
         */
        turboHiker::Vector2d mWorldViewCenter;

};
} // namespace turboHikerSFML
