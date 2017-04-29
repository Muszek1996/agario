#ifndef PLAYER_H
#define PLAYER_H

#include "LibsAndDeclarations.h"

class Player
{
public:
	Player();
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;
	~Player();

private:
	const float speed;
	sf::CircleShape shape;
	sf::Vector2f velocity;

public:
	bool init(sf::Vector2f position, float radius, sf::Color color);
	bool update(float dt);
	void draw(sf::RenderWindow &window);
	void release();

	sf::Vector2f position() { return shape.getPosition(); }
};
#endif