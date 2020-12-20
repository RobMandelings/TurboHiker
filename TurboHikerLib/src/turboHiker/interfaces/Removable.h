//
// Created by RobMa on 20/12/2020.
//

#ifndef TURBOHIKER_REMOVABLE_H
#define TURBOHIKER_REMOVABLE_H

namespace turboHiker {
class Removable
{

public:
        void markForRemoval();
        bool isMarkedForRemoval() const const;

private:
        bool mMarkedForRemoval;
};
} // namespace turboHiker

#endif // TURBOHIKER_REMOVABLE_H
