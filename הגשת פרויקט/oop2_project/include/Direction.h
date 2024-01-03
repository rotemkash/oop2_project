#pragma once

#include <SFML/Graphics.hpp>

enum class Direction {
  Jump,
  JumpRight,
  JumpLeft,
  AttackRight,
  AttackLeft,
  Down,
  Right,
  Left,
  Stay,
  Max,
};

sf::Vector2f toVector(sf::Keyboard::Key keyCode);

Direction toDirection(sf::Vector2f vec);
