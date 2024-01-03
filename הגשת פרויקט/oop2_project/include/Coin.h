#pragma once
#include "Animation.h"
#include "Resources.h"
#include "StaticObject.h"

class Coin : public StaticObject {
 private:
  sf::Sprite m_sprite;
  Animation m_animation;
  bool m_isEaten = false;
  //
  //
 public:
  Coin(float x, float y);

  void drawObject(sf::RenderWindow& target) override;
  //
  void gotEaten();

  bool isEaten() const;
  //
};
