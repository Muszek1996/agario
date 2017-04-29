#ifndef FOODORGANIZER_H
#define FOODORGANIZER_H

#include "LibsAndDeclarations.h"
#include "Food.h"
#include "Apple.h"

class FoodOrganizer {
private:
//FIXME: wywalic objects na wektorach i pozmeniac wszedzie te wektory
  //std::vector<Food*> objects; 
	std::vector<Apple> objects; /**< Stores Food objects */ 

public:

	/**
	*	Constructor of the FoodOrganizer object.
	*/
	FoodOrganizer();

	/**
	*	TODO: FoodOrganizer.init()
	* Tworzenie poczatkowej ilosci jedzenia
	*/
	void init();

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

	//TODO: FoodOrganizer.release()
	void release();

	// TODO: nie przesylac obiektu do funkcji, 
	// niech funkcja sama zajmie sie tworzeniem obiektu nowego
	/**
	* Adds new Food object to the stored objects.
	* @param f pointer to the Food object, that must be created before
	*/
	void add(Food* f);

	void add2(sf::Vector2f position);

	/**
	*	TODO: FoodOrganizer.del()
	*/
	void del();

	// TODO: zmienic (stworzyc nową, oddzielną) na funkcje niezalezna od obiektu Food,
	// zeby sprawdzac kolizje miedzy konkretnymi typami obiektow
	// detectCollision(sf::CircleShape, sf::CircleShape);
	/**
	* Detects the collision between all Food objects and player.
	* @param player object with whitch it is checking collision
	*/
	void detectCollision(sf::CircleShape &player);
};

#endif

