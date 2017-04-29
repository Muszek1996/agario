#include "FoodOrganizer.h"

FoodOrganizer::FoodOrganizer() { this->objects.reserve(20); }

void FoodOrganizer::init() {}

void FoodOrganizer::update() {}

void FoodOrganizer::draw(sf::RenderWindow &window) {
  for (auto i : objects) {
    i->draw(window);
  }
}

void FoodOrganizer::release() {}

void FoodOrganizer::add(Food *f) { this->objects.push_back(f); }

void FoodOrganizer::add2(sf::Vector2f position) {
  objects2.emplace_back(position);
}

void FoodOrganizer::del() {}

void FoodOrganizer::detectCollision(sf::CircleShape &player) {
  sf::Vector2f playerPos = player.getPosition();
  float playerRadius = player.getRadius();
  playerPos.x += playerRadius;
  playerPos.y += playerRadius;

  sf::Vector2f objPos;
  float objRadius, temp2, temp3;

  auto it = objects.begin();
  while (it != objects.end()) {
    objPos = (*it)->getPosition();
    if ((*it)->getType() == "Apple") {
      objRadius = (*it)->getUnique();
      objPos.x += objRadius;
      objPos.y += objRadius;

      temp2 = playerRadius + objRadius;
      temp2 *= temp2;

      temp3 = std::pow((playerPos.x - objPos.x), 2) +
              std::pow((playerPos.y - objPos.y), 2);

      // true- collision detected
      if (temp2 >= temp3) {
        // i->setPosition(sf::Vector2f(0., 0.));
        std::swap(*it, objects.back()); // swap with the last element
        if (objects.size() != 0)
          objects.pop_back(); // delete last element
        --it; // cofam bo zamienilem z ostatnim elementem, tez trzeba go
              // sprawdzic
      }
    }
    ++it;
  }
}