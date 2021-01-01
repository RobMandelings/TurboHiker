//
// Created by RobMa on 28/12/2020.
//

#ifndef TURBOHIKER_COLOR_H
#define TURBOHIKER_COLOR_H

#include <SFML/Graphics/Color.hpp>
namespace turboHikerSFML {
class Color
{

public:
        Color(double red, double green, double blue);

        void setRed(double red);

        void setGreen(double green);

        void setBlue(double blue);

        void setColor(const sf::Color& color);

        double getRed() const;

        double getGreen() const;

        double getBlue() const;

        /**
         * Converts it to a Color class in SFML (with rgb values ranging [0, 255]
         * @return
         */
        sf::Color getSFMLColor() const;

private:
        double mRed;
        double mGreen;
        double mBlue;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_COLOR_H
