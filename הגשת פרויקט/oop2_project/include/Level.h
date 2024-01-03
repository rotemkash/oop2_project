#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

class Level {
 private:
  sf::Texture g_texture;
  sf::Sprite g1;

  std::vector<sf::Sprite> m_ground;

  //
  //
 public:
  Level();

  void DrawLevel(sf::RenderWindow *window);
  //
  //
};