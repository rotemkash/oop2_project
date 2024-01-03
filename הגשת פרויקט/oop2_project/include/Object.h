#pragma once

#include <SFML/Graphics.hpp>

class Object {
 private:
  sf::Sprite& m_sprite;

 public:
  Object(sf::Sprite& sprite);

  virtual void drawObject(sf::RenderWindow& target) = 0;

  sf::Vector2f getObjectPos() const;

  void setObjectPos(sf::Vector2f newPos);

  sf::FloatRect getObjBounds() const;

  virtual ~Object() = default;
};
