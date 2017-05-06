#include "Gameplay.h"

// sterowac fizyką poprzez nadanie siły

Gameplay::Gameplay() {}

Gameplay::~Gameplay() { release(); }

void Gameplay::updateCamera() {}

bool Gameplay::init() {
  camV = 384.;
  mCamPosition.x = -50.;
  mCamPosition.y = -25.;
  camera.reset(sf::FloatRect(mCamPosition.x, mCamPosition.y, 683, 384));
  //---Origin point
  origin.setPosition(-1., -1.);
  origin.setRadius(1.);
  origin.setFillColor(sf::Color(0, 0, 0));
  //----
  player.init(sf::Vector2f(0., 0.), 20., sf::Color(0, 0, 255));
  pSpeed = player.getSpeed();
  //---add 25 food objects
  foodOrg.initRand(25);
  //----
  return true;
}

bool Gameplay::update(float dt) {
  updateCamera();

  //---- TODO: change it to the class that handles the inputs
  mVelocity.x = 0;
  mVelocity.y = 0;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    mVelocity.y -= pSpeed;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    mVelocity.x -= pSpeed;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    mVelocity.y += pSpeed;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    mVelocity.x += pSpeed;

  player.move(mVelocity * dt);
  //----
  mCamVelocity.x = 0;
  mCamVelocity.y = 0;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    mCamVelocity.y -= pSpeed;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
    mCamVelocity.x -= pSpeed;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    mCamVelocity.y += pSpeed;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    mCamVelocity.x += pSpeed;

  // camera.move(mCamVelocity * dt);
  mCamPosition.x += mCamVelocity.x * dt;
  mCamPosition.y += mCamVelocity.y * dt;
  //----

  foodOrg.detectCollision(player.getShape());

  return true;
}

void Gameplay::draw(sf::RenderWindow &window) {
  camera.reset(sf::FloatRect(
      mCamPosition.x, mCamPosition.y,
      camV * (float)window.getSize().x / (float)window.getSize().y, camV));
  window.setView(camera);

  window.clear(sf::Color(0, 255, 0));
  window.draw(origin);

  foodOrg.draw(window);
  player.draw(window);

  window.setView(window.getDefaultView());
}

void Gameplay::release() {}
