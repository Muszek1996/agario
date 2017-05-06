#ifndef FOODORGANIZER_H
#define FOODORGANIZER_H

#include "Apple.h"
#include "Food.h"
#include "LibsAndDeclarations.h"

class FoodOrganizer {
private:
  std::vector<Apple> apples; /**< Stores Apple objects */

  std::random_device rd; /**< to generate random position */
public:
  /**
  *	Constructor of the FoodOrganizer object.
  */
  FoodOrganizer();

  /**
  * Initialise with some amount of Food
  * @param no number of Food to add
  */
  void initRand(int no);

  /**
  *	TODO: FoodOrganizer.update()
  * Dodanie jedzenia w losowych miejscach co okreslona ilosc czasu
  */
  void update();

  /**
  * Handles the drawing of the Food objects.
  * @param window where to draw
  */
  void draw(sf::RenderWindow &window);

  // TODO: FoodOrganizer.release()
  void release();

  /**
  * Adds new Apple object to the stored objects.
  * @param position of the new object
  */
  void addApple(sf::Vector2f position);

  /**
  *	TODO: FoodOrganizer.del()
  */
  void del();

  /**
  * Detects the collision between all Food objects and player.
  * @param player object with whitch it is checking collision
  */
  void detectCollision(sf::CircleShape &player);
};

#endif
