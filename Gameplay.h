#include "Apple.h"
#include "FoodOrganizer.h"
#include "GameStage.h"
#include "LibsAndDeclarations.h"
#include "Player.h"

class Gameplay : public GameStage {
public:
  Gameplay();
  Gameplay(const Gameplay &) = delete;
  Gameplay &operator=(const Gameplay &) = delete;
  virtual ~Gameplay();

private:
  sf::View camera;

  void updateCamera();
  float camV;
  sf::CircleShape origin;
  sf::Vector2f mVelocity;
  sf::Vector2f mCamVelocity;
  sf::Vector2f mCamPosition;

  FoodOrganizer foodOrg;
  Apple *a1;

  Player player;
  float pSpeed;

public:
  virtual bool init();
  virtual bool update(float dt);
  virtual void draw(sf::RenderWindow &window);
  virtual void release();
};
