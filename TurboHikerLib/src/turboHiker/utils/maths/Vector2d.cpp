//
// Created by RobMa on 19/12/2020.
//

#include "Vector2d.h"

turboHiker::Vector2d::Vector2d(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

turboHiker::Vector2d turboHiker::Vector2d::operator*(std::chrono::duration<double> seconds)
{
        return (*this)*seconds.count();
}

turboHiker::Vector2d turboHiker::Vector2d::operator*(double scalar) const {
        return Vector2d(this->x * scalar, this->y * scalar);
}

turboHiker::Vector2d turboHiker::Vector2d::operator+(const turboHiker::Vector2d& vector2D) const
{
        return Vector2d(this->x + vector2D.x, this->y + vector2D.y);
}
turboHiker::Vector2d turboHiker::Vector2d::operator-(const turboHiker::Vector2d& vector2D) const
{
        return Vector2d(this->x - vector2D.x, this->y - vector2D.y);
}
turboHiker::Vector2d& turboHiker::Vector2d::operator+=(const turboHiker::Vector2d& vector2D)
{
        this->x + vector2D.x;
        this->y + vector2D.y;
        return *this;
}
turboHiker::Vector2d& turboHiker::Vector2d::operator-=(const turboHiker::Vector2d& vector2D)
{
        this->x - vector2D.x;
        this->y - vector2D.y;
        return *this;
}
