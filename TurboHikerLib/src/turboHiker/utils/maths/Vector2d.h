//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_VECTOR2D_H
#define TURBOHIKER_VECTOR2D_H

namespace turboHiker {
struct Vector2d
{
        double xCoord;
        double yCoord;

        Vector2d(double xCoord, double yCoord);

        Vector2d operator+(const Vector2d& vector2D) const;
        Vector2d operator-(const Vector2d& vector2D) const;

        Vector2d& operator+=(const Vector2d& vector2D);
        Vector2d& operator-=(const Vector2d& vector2D);


};
} // namespace turboHiker

#endif // TURBOHIKER_VECTOR2D_H
