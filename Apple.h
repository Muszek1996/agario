#ifndef APPLE_H
#define APPLE_H

#include "Food.h"
#include "LibsAndDeclarations.h"

class Apple : public Food {
private:
  sf::Color color;
  std::string type;
  sf::CircleShape shape;
	float radius = 5;

public:
  Apple(sf::Vector2f position);
  ~Apple();
  void draw(sf::RenderWindow &window);
	void setPosition(sf::Vector2f);
	sf::Vector2f getPosition();
	float getUnique();
	std::string getType();
};

#endif