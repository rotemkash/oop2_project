#pragma once

#include "Animation.h"  
#include "Object.h"

class MovingObject : public Object {
 private:
  Direction m_dir = Direction::Stay;
  float m_speed;

 public:
  sf::Vector2f m_moveCoords = sf::Vector2f(0.0f, 0.0f);

  MovingObject(sf::Sprite& sprite, float speed);

  void setSpeed(float speed);

  float getSpeed() const;

  void setDirection(Direction newDir);

  Direction getDirection() const;

  virtual void move(float delta) = 0;
};