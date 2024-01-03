#include "Puddle.h"

Puddle::Puddle(float x, float y) : StaticObject(m_sprite) {
  //
  m_texture.loadFromFile("sea.jpg");
  m_sprite.setTexture(m_texture);
  setObjectPos(sf::Vector2f(x, y));
  m_sprite.setScale(1, 0.5);
  //
}

void Puddle::drawObject(sf::RenderWindow& target) { target.draw(m_sprite); }
