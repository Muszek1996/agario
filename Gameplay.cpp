#include "Gameplay.h"

//sterowac fizyką poprzez nadanie siły

Gameplay::Gameplay() {}

Gameplay::~Gameplay() { release(); }

void Gameplay::updateCamera() {}

bool Gameplay::init() {
	camV = 384.;
	mCamPosition.x = -50.;
	mCamPosition.y = -25.;
  camera.reset(sf::FloatRect(mCamPosition.x, mCamPosition.y, 683, 384));
  //--Origin point
  origin.setPosition(-1., -1.);
  origin.setRadius(1.);
  origin.setFillColor(sf::Color(0, 0, 0));
  // TODO: change to player init
  kolo.setFillColor(sf::Color(0, 0, 255));
  kolo.setPosition(0., 0.);
  kolo.setRadius(20.);
  mSpeed = 100.;
  //------generate random numbers
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<> randX(0,683);
  std::uniform_int_distribution<> randY(0,384);
  //----add 25 food objects
  // TODO: zrobic to w foodOrg.init()
  for(int i = 0; i<25; ++i){
    //a1 = new Apple(sf::Vector2f(randX(mt),randY(mt)));
    //foodOrg.add(a1);
    foodOrg.add(new Apple(sf::Vector2f(randX(mt),randY(mt))));
  }
  //----
  return true;
}

bool Gameplay::update(float dt) {
  updateCamera();

  //----
  mVelocity.x = 0;
  mVelocity.y = 0;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    mVelocity.y -= mSpeed;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    mVelocity.x -= mSpeed;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    mVelocity.y += mSpeed;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    mVelocity.x += mSpeed;

  kolo.move(mVelocity * dt);
  //----
  mCamVelocity.x = 0;
  mCamVelocity.y = 0;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    mCamVelocity.y -= mSpeed;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
    mCamVelocity.x -= mSpeed;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    mCamVelocity.y += mSpeed;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    mCamVelocity.x += mSpeed;

  //camera.move(mCamVelocity * dt);
	mCamPosition.x += mCamVelocity.x * dt;
	mCamPosition.y += mCamVelocity.y * dt;
	//----
	
  foodOrg.detectCollision(kolo);

  return true;
}

void Gameplay::draw(sf::RenderWindow &window) {	
  camera.reset(sf::FloatRect(mCamPosition.x, mCamPosition.y, camV * (float)window.getSize().x/(float)window.getSize().y, camV));	
  window.setView(camera);

  window.clear(sf::Color(0, 255, 0));
  window.draw(origin);

  window.draw(kolo);

  foodOrg.draw(window);

  window.setView(window.getDefaultView());
}

void Gameplay::release() {}
