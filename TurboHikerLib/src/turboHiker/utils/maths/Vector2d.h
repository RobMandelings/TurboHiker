//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_VECTOR2D_H
#define TURBOHIKER_VECTOR2D_H

#include <chrono>
#include <iostream>

namespace turboHiker {

/**
 * Simple class which holds two doubles and represents a vector in 2D space for easy calculations
 */
struct Vector2d
{

        /**
         * The x coordinate of the vector
         */
        double x;

        /**
         * The y coordinate of the vector
         */
        double y;

        /**
         * Simple constructor
         * @param xCoord: the x coordinate of the vector
         * @param yCoord: the y coordainte of the vector
         */
        Vector2d(double xCoord, double yCoord);

        /**
         * Operator overload for operator * to easily multiply by the amount of seconds (used by updates to multiply by
         * the timeStep)
         * @param seconds
         * @return
         */
        Vector2d operator*(std::chrono::duration<double> seconds) const;

        /**
         * Multiplies the vector by a given scalar
         * @param scalar: the scalar to multiply this vector with
         * @return the new Vector constructed from the old vector * scalar
         */
        Vector2d operator*(double scalar) const;

        /**
         * Multiplies a given vector by the amount of seconds. Used for convenience and is actually just a
         * multiplication with a scalar
         * @param seconds: the seconds to multiply the vector with
         * @return reference to the multiplied vector
         */
        Vector2d& operator*=(std::chrono::duration<double> seconds);

        /**
         * Multiplies a given vector by a given scalar. Used for convenience and is actually just a multiplication with
         * a scalar
         * @param seconds: the seconds to multiply the vector with
         * @return reference to the multiplied vector
         */
        Vector2d& operator*=(double scalar);

        /**
         * Adds a given vector to this vector and returns the result
         * @param vector2D: the given vector to add to the other vector
         * @return the newly constructed vector
         */
        Vector2d operator+(const Vector2d& vector2D) const;

        /**
         * subtracts a given vector to this vector and returns the result
         * @param vector2D: the given vector to add to the other vector
         * @return the newly constructed vector
         */
        Vector2d operator-(const Vector2d& vector2D) const;

        /**
         * Adds a given vector to this vector and returns a reference to this vector
         * @param vector2D: the given vector to add to the other vector
         * @return reference to this vector
         */
        Vector2d& operator+=(const Vector2d& vector2D);

        /**
         * Subtracts a given vector to this vector and returns a reference to this vector
         * @param vector2D: the given vector to add to the other vector
         * @return reference to this vector
         */
        Vector2d& operator-=(const Vector2d& vector2D);
};

/**
 * Simple operator overload to be able to easily print the vector coordinates onto the screen
 * @param os: the current outputstream
 * @param vector2D: the vector to print
 * @return reference to the output stream
 */
std::ostream& operator<<(std::ostream& os, const Vector2d& vector2D);

} // namespace turboHiker

#endif // TURBOHIKER_VECTOR2D_H
