#include "Object.h"

Object::Object(sf::Sprite& sprite) : m_sprite(sprite) {}

sf::Vector2f Object::getObjectPos() const { return m_sprite.getPosition(); }

void Object::setObjectPos(sf::Vector2f newPos) { m_sprite.setPosition(newPos); }

sf::FloatRect Object::getObjBounds() const {
  return m_sprite.getGlobalBounds();
}
