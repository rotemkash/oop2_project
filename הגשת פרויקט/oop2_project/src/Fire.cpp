#include "Fire.h"

Fire::Fire(float x, float y)
    : StaticObject(m_sprite),
      m_animation(Resources::instance().animationData(Resources::Fire),
                  Direction::Stay, m_sprite) {}

void Fire::drawObject(sf::RenderWindow& target) {
  m_animation.update(0.3f);
  target.draw(m_sprite);
}
