//
// Created by Rob Mandelings on 5/01/2021.
//

#pragma once

#include <SFML/Graphics/Font.hpp>
#include <map>
#include <mutex>

namespace turboHiker {
enum class Font
{
        ARIAL
};

class FontManager
{

public:
        FontManager(const FontManager& other) = delete;
        void operator=(const FontManager& other) = delete;

        static FontManager& get();

        const sf::Font& getFont(const Font& font);

private:
        std::pair<Font, sf::Font> initializeFont(const Font& font);

        static std::mutex mMutex;

        FontManager() = default;

        std::map<Font, sf::Font> mFonts;
};
} // namespace turboHiker