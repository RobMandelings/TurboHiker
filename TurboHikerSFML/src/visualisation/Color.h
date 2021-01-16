//
// Created by RobMa on 28/12/2020.
//

#ifndef TURBOHIKER_COLOR_H
#define TURBOHIKER_COLOR_H

#include <SFML/Graphics/Color.hpp>
namespace turboHikerSFML {

/**
 * Color class, with RGB values ranging [0,1] instead of [0,255] which is a lot easier to work with
 */
class Color
{

public:
        /**
         * Simple constructor
         * @param red: the red component of the color
         * @param green: the green component of the color
         * @param blue: the blue component of the color
         */
        Color(double red, double green, double blue);

        /**
         * Set the red value ranging [0, 1]
         * @param red: the red value
         */
        void setRed(double red);

        /**
         * Set the green value ranging [0, 1]
         * @param green: the green value
         */
        void setGreen(double green);

        /**
         * Set the blue value ranging [0, 1]
         * @param blue: the blue value
         */
        void setBlue(double blue);

        /**
         * Set the new color
         * @param color: the new color
         */
        void setColor(const sf::Color& color);

        /**
         * Gets the red value of the color
         * @return the red value
         */
        double getRed() const;

        /**
         * Gets the green value of the color
         * @return the green value
         */
        double getGreen() const;

        /**
         * Gets the blue value of the color
         * @return the blue value
         */
        double getBlue() const;

        /**
         * Converts it to a Color class in SFML (with rgb values ranging [0, 255]
         * @return
         */
        sf::Color getSFMLColor() const;

private:
        /**
         * Red component of the RGB Color
         */
        double mRed;

        /**
         * Green component of the RGB Color
         */
        double mGreen;

        /**
         * Blue component of the RGB Color
         */
        double mBlue;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_COLOR_H
