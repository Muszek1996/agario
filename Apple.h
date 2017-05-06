#ifndef APPLE_H
#define APPLE_H

#include "Food.h"
#include "LibsAndDeclarations.h"
const float APPLE_RADIUS = 5;

class Apple : public Food {
private:
  sf::Color color;
  std::string type;
  sf::CircleShape shape;
  float radius = APPLE_RADIUS;

public:
  Apple(sf::Vector2f position);
  ~Apple();
  void draw(sf::RenderWindow &window);
  void setPosition(sf::Vector2f);
  sf::Vector2f getPosition();
  std::string getType();

  float getRadius();
  sf::CircleShape &getShape();
};

#endif