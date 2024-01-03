#pragma once

#include "StaticObject.h"
class Platform : public StaticObject {
 private:
  sf::Sprite m_sprite;
  sf::Texture m_texture;

 public:
  Platform(float x, float y);

  void drawObject(sf::RenderWindow& target) override;
  //
  //
};
