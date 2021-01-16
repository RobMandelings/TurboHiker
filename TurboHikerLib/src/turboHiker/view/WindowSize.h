//
// Created by Rob Mandelings on 25/12/2020.
//

#pragma once

namespace turboHiker {

/**
 * WindowSize used by the transformation class. Can be set by the visual implementation of the class.
 */
class WindowSize
{

public:

        /**
         * Simple constructor
         * @param width: the width of the window, in pixels
         * @param height: the height of the window, in pixels
         */
        WindowSize(int width, int height);

        /**
         * Simple getter
         * @return the width of the window, in pixels
         */
        int getWidth() const;

        /**
         * Simple setter
         * @param width: the new width of the window
         */
        void setWidth(int width);

        /**
         * Simple getter
         * @return height: the height of the window
         */
        int getHeight() const;

        /**
         * Simple setter
         * @param height: the new height of the window
         */
        void setHeight(int height);

private:

        /**
         * The current width of the window
         */
        int mWidth;

        /**
         * The current height of the window
         */
        int mHeight;

};
} // namespace turboHikerSFML
