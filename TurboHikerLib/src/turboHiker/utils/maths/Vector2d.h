//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_VECTOR2D_H
#define TURBOHIKER_VECTOR2D_H

#include <chrono>
#include <iostream>

namespace turboHiker {
struct Vector2d
{
        double x;
        double y;

        Vector2d(double xCoord, double yCoord);

        /**
         * Operator overload for operator * to easily multiply by the amount of seconds (used by updates to multiply by the timeStep)
         * @param seconds
         * @return
         */
        Vector2d operator*(std::chrono::duration<double> seconds) const;
        Vector2d operator*(double scalar) const;

        Vector2d& operator*=(std::chrono::duration<double> seconds);
        Vector2d& operator*=(double scalar);

        Vector2d operator+(const Vector2d& vector2D) const;
        Vector2d operator-(const Vector2d& vector2D) const;

        Vector2d& operator+=(const Vector2d& vector2D);
        Vector2d& operator-=(const Vector2d& vector2D);

        friend std::ostream& operator<<(std::ostream& os, const Vector2d& vector2D);


};
} // namespace turboHiker

#endif // TURBOHIKER_VECTOR2D_H
