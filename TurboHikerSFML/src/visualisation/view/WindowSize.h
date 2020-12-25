//
// Created by Rob Mandelings on 25/12/2020.
//

#pragma once

namespace turboHikerSFML {
class WindowSize
{

public:
        WindowSize(int width, int height);
        int getWidth() const;
        void setWidth(int width);
        int getHeight() const;
        void setHeight(int height);

private:

        int mWidth;
        int mHeight;

};
} // namespace turboHikerSFML
