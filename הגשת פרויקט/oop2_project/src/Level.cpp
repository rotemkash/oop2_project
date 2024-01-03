#include "Level.h"

Level::Level() {
  g_texture.loadFromFile("ground.png");
  g1.setTexture(g_texture);
  g1.setPosition(400.f, 2200.f);
  m_ground.push_back(g1);
  //
}

void Level::DrawLevel(sf::RenderWindow* window) {
  for (size_t i = 0; i < m_ground.size(); i++) {
    window->draw(m_ground[i]);
  }
}
