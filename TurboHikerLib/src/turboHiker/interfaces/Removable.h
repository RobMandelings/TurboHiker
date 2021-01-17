//
// Created by RobMa on 20/12/2020.
//

#ifndef TURBOHIKER_REMOVABLE_H
#define TURBOHIKER_REMOVABLE_H

namespace turboHiker {

/**
 * Implemented by classes which can be marked for removal so they will be deleted at the corresponding time (such as SceneNodes)
 */
class Removable
{

public:

        /**
         * Simple constructor
         */
        Removable();

        /**
         * Marks the object to be removed. Cannot be undone
         */
        void markForRemoval();

        /**
         * Checks if the object is marked for removal
         * @return true if this is the case, false if not
         */
        bool isMarkedForRemoval() const;

private:

        /**
         * True if the object has been marked for removal, false if not
         */
        bool mMarkedForRemoval;
};
} // namespace turboHiker

#endif // TURBOHIKER_REMOVABLE_H
