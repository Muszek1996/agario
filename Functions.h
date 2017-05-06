#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "LibsAndDeclarations.h"

/**
* Detects the collision between two CircleShaped objects.
* @param ob1 first object
* @param ob2 second object
*/
bool detectCollisionCvsC(const sf::CircleShape &ob1,
                         const sf::CircleShape &ob2);

#endif