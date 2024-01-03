
#pragma once

#include <SFML/Graphics.hpp>

#include "AnimationData.h"
#include "Direction.h"

class Animation {
 public:
  Animation(const AnimationData& data, Direction dir, sf::Sprite& sprite);

  // Set the direction; the sprite will take the relevant texture rect
  void direction(Direction dir);

  // Add more time to the elapsed time; if enough time passed, it
  // updates the sprite to show the next frame in the animation
  void update(float delta);

  void nextAnimation();

 private:
  // Update the sprite to take the correct part of the texture,
  // based on current dir and index
  void update();

  const AnimationData& m_data;
  float m_elapsed = 0.0f;
  Direction m_dir = Direction::Right; // Up -> Jump
  int m_index = 0;
  sf::Sprite& m_sprite;
};