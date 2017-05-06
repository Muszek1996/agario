#include "Apple.h"

Apple::Apple(sf::Vector2f position)
    : color(sf::Color(255, 0, 0)), type("Apple") {
  this->shape.setPosition(position);
  this->shape.setRadius(radius);
  this->shape.setFillColor(color);
}

Apple::~Apple() {}

void Apple::draw(sf::RenderWindow &window) { window.draw(this->shape); }

void Apple::setPosition(sf::Vector2f v) { this->shape.setPosition(v); }

sf::Vector2f Apple::getPosition() { return this->shape.getPosition(); }

float Apple::getRadius() { return this->radius; }

std::string Apple::getType() { return this->type; }

sf::CircleShape &Apple::getShape() {return this->shape;}