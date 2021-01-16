//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

#include <ostream>
namespace turboHiker {
class BoundingBox
{

public:

        /**
         * Returns an instance of an empty bounding box
         * @return instance of the empty boundingBox
         */
        static const BoundingBox& getEmptyBB();

        /**
         * BoundingBox that is used for collision detection with several SceneNodes / Entities
         * @param left: the leftmost coordinate of the boundingbox
         * @param bottom: the bottom coordinate of the boundingbox
         * @param width: the width of the boundingBox
         * @param height: the height of the boundingBox
         */
        BoundingBox(double left, double bottom, double width, double height);

        /**
         * Simple getter
         * @return get the left coordinate of the boundingBox
         */
        double getLeft() const;

        /**
         * Simple getter
         * @return get the top coordinate of the boundingBox
         */
        double getTop() const;

        /**
         * Simple getter
         * @return get the bottom coordinate of the boundingBox
         */
        double getBottom() const;

        /**
         * Simple getter
         * @return get the right coordinate of the boundingBox
         */
        double getRight() const;

        /**
         * Simple getter
         * @return get the width of the boundingBox
         */
        double getWidth() const;

        /**
         * Simple getter
         * @return get the height of the boundingBox
         */
        double getHeight() const;

        /**
         * Checks if this boundingBox is empty (meaning its width and/or size is 0). The empty boundingBox is used for objects who do not participate in collision detection
         * @return true if the boundingBox is empty
         */
        bool empty() const;

private:

        /** The left coordinate of the bounding box */
        double mLeft;

        /** The bottom coordinate of the bounding box */
        double mBottom;

        /** The width of the bounding box */
        double mWidth;

        /** The height of the bounding box */
        double mHeight;
};

/**
 * Operator overload to be able to represent the boundingBox in the terminal, for debugging purposes for example
 * @param ostream: the current outputstream
 * @param boundingBox: the boundingBox to print
 * @return the modified ostream
 */
std::ostream& operator<<(std::ostream& ostream, const BoundingBox& boundingBox);

} // namespace turboHiker