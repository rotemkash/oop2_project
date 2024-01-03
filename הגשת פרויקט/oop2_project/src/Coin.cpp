#include "Coin.h"

Coin::Coin(float x, float y)
    : StaticObject(m_sprite),
      m_animation(Resources::instance().animationData(Resources::Coin),
                  Direction::Stay, m_sprite) {
  setObjectPos({x, y});
}

void Coin::drawObject(sf::RenderWindow& target) {
  m_animation.update(0.3f);
  target.draw(m_sprite);
}

void Coin::gotEaten() { m_isEaten = true; }

bool Coin::isEaten() const { return m_isEaten; }
