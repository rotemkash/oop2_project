#pragma once
#include "Animation.h"
#include "Resources.h"
#include "StaticObject.h"

class Fire : public StaticObject {
 private:
  sf::Sprite m_sprite;
  Animation m_animation;

 public:
  Fire(float x, float y);

  void drawObject(sf::RenderWindow& target) override;
};
