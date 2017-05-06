#include "Functions.h"

bool detectCollisionCvsC(const sf::CircleShape &ob1,
                         const sf::CircleShape &ob2) {
  sf::Vector2f ob1Position = ob1.getPosition(), ob2Position = ob2.getPosition();
  float ob1Radius = ob1.getRadius(), ob2Radius = ob2.getRadius();

  // move the origin points to the center of the objects
  ob1Position.x += ob1Radius;
  ob1Position.y += ob1Radius;
  ob2Position.x += ob2Radius;
  ob2Position.y += ob2Radius;

  float rSum = ob1.getRadius() + ob2.getRadius();
  rSum *= rSum;

  return rSum >= std::pow((ob1Position.x - ob2Position.x), 2) +
                     std::pow((ob1Position.y - ob2Position.y), 2);
}
