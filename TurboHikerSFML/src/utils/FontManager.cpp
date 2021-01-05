//
// Created by Rob Mandelings on 5/01/2021.
//

#include "FontManager.h"
#include <cassert>

using namespace turboHiker;

FontManager& FontManager::get()
{

        std::lock_guard<std::mutex> lock(mMutex);
        static FontManager instance;

        return instance;
}

std::mutex FontManager::mMutex;

const sf::Font& FontManager::getFont(const Font& font)
{
        auto foundFont = mFonts.find(font);
        if (foundFont == mFonts.end()) {
                mFonts.insert(initializeFont(font));
                foundFont = mFonts.find(font);
        }
        assert(foundFont != mFonts.end() &&
               "The font was still not initialized. Probably not defined in initialize font.");

        return foundFont->second;
}

std::pair<Font, sf::Font> FontManager::initializeFont(const Font& font)
{
        std::pair<Font, sf::Font> fontPair;

        assert(mFonts.find(font) == mFonts.end());

        switch (font) {
        case Font::ARIAL:
                sf::Font theFont;
                if (!theFont.loadFromFile("res/fonts/arial.ttf")) {
                        throw std::runtime_error("The font ARIAL couldn't be loaded from file.");
                }

                fontPair = {font, theFont};
                break;
        }

        return fontPair;
}
