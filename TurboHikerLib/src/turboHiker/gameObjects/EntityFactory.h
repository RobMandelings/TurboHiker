//
// Created by RobMa on 21/12/2020.
//

#ifndef TURBOHIKER_ENTITYFACTORY_H
#define TURBOHIKER_ENTITYFACTORY_H

namespace turboHiker {

class SceneNode;

/**
 * An Abstract Factory to create entities (Specific GameObjects). Their visual representation must be implemented by the
 * visualization library used (Such as SFML)
 */
class EntityFactory
{

        SceneNode* createTestObject();

};
} // namespace turboHiker

#endif // TURBOHIKER_ENTITYFACTORY_H
