#ifndef FOOD_H
#define FOOD_H

#include "LibsAndDeclarations.h"

class Food {
protected:
	sf::Color color;
	std::string type;

public:
  Food();
	Food(sf::Vector2f position);
	virtual ~Food();
	virtual void draw(sf::RenderWindow &window) = 0;
	virtual void setPosition(sf::Vector2f) = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual float getUnique() = 0;
	virtual std::string getType() = 0;
};

#endif