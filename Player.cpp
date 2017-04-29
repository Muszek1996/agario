#include "Player.h"

Player::Player() : speed(100.), velocity(sf::Vector2f(0., 0.)) {}

Player::~Player() {}

bool Player::init(sf::Vector2f position, float radius, sf::Color color) {
	// this->shape.setFillColor(sf::Color(0, 0, 255));
  // this->shape.setPosition(0., 0.);
  // this->shape.setRadius(20.); 
	this->shape.setFillColor(color);
  this->shape.setPosition(position);
  this->shape.setRadius(radius);
	return true; }

bool Player::update(float dt) { return true; }

void Player::draw(sf::RenderWindow &window) { window.draw(this->shape); }

void Player::release() {}