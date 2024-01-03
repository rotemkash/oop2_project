#pragma once

#include "StaticObject.h"

class Puddle : public StaticObject {
 private:
  sf::Sprite m_sprite;
  sf::Texture m_texture;
  bool m_isEaten = false;
 public:
  Puddle(float x, float y);

  void drawObject(sf::RenderWindow& target) override;
  //
  //
};
