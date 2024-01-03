#include "Platform.h"

Platform::Platform(float x, float y) : StaticObject(m_sprite) {
  //
  m_texture.loadFromFile("platform.png");
  m_sprite.setTexture(m_texture);
  // m_sprite.setPosition(sf::Vector2f(x, y));
  setObjectPos(sf::Vector2f(x, y));
  m_sprite.setScale(0.5, 0.5);
  //
}

void Platform::drawObject(sf::RenderWindow& target) { target.draw(m_sprite); }
