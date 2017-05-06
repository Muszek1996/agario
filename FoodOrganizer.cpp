#include "FoodOrganizer.h"

FoodOrganizer::FoodOrganizer() { this->apples.reserve(20); }

void FoodOrganizer::initRand(int no) {
  //---generate random numbers
  std::mt19937 mt(rd());
  // TODO: change arguments to depend on window size
  std::uniform_int_distribution<> randX(0, 683);
  std::uniform_int_distribution<> randY(0, 384);
  //---
  for (int i = 0; i < no; ++i)
    this->addApple(sf::Vector2f(sf::Vector2f(randX(mt), randY(mt))));
}

void FoodOrganizer::update() {}

void FoodOrganizer::draw(sf::RenderWindow &window) {
  for (auto i : apples) {
    i.draw(window);
  }
}

void FoodOrganizer::release() {}

void FoodOrganizer::addApple(sf::Vector2f position) {
  apples.emplace_back(position);
}

void FoodOrganizer::del() {}

void FoodOrganizer::detectCollision(sf::CircleShape &player) {
  auto it = apples.begin();
  while (it != apples.end()) {
    if (detectCollisionCvsC((*it).getShape(), player)) {
      std::swap(*it, apples.back()); // swap with the last element
      if (apples.size() != 0)
        apples.pop_back(); // delete last element
      --it; // cofam bo zamienilem z ostatnim elementem, tez trzeba go
            // sprawdzic
    }
    ++it;
  }
}