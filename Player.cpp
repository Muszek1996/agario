#include "Player.h"

Player::Player() : speed(100.), velocity(sf::Vector2f(0., 0.)) {}

Player::~Player() {}

bool Player::init(sf::Vector2f position, float radius, sf::Color color) {
  this->shape.setPosition(position);
  this->shape.setRadius(radius);
  this->shape.setFillColor(color);
  return true;
}

bool Player::update(float dt) { return true; }

void Player::draw(sf::RenderWindow &window) { window.draw(this->shape); }

void Player::release() {}

void Player::move(sf::Vector2f v) { shape.move(v); }

sf::CircleShape &Player::getShape() { return this->shape; }