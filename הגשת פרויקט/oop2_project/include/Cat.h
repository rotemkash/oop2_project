#pragma once

#include <SFML/Graphics.hpp>

#include "Animation.h"
#include "Direction.h"
#include "MovingObject.h"
#include "Resources.h"

class Cat : public MovingObject {
 public:
  Cat(float x, float y);

  void move(float delta) override;

  void drawObject(sf::RenderWindow& target) override;

  void collideWithFish();

 private:
  sf::Sprite m_sprite;
  Animation m_animation;
  float DURATION = sf::seconds(2.0f).asSeconds();
  float m_elapsedTime = 0.0f;

  bool m_isMoving = true;
};
