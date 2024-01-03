#include "Cat.h"

// constexpr auto GhostSpeed = 35.f;

Cat::Cat(float x, float y)
    : MovingObject(m_sprite, 5.0f),
      m_animation(Resources::instance().animationData(Resources::Cat),
                  Direction::Right, m_sprite) {
  m_sprite.setOrigin(85.0f / 2.0f, 100.0f / 2.0f);
  m_sprite.setPosition(x, y);
  m_moveCoords.x = 1.0f;
}

void Cat::move(float delta) {
  // direction
  if (m_isMoving) {
    m_elapsedTime += delta;
    if (m_elapsedTime >= DURATION) {
      if (getDirection() == Direction::Right) {
        m_moveCoords.x = -1.0f;
      } else if (getDirection() == Direction::Left) {
        m_moveCoords.x = 1.0f;
      }
      m_elapsedTime = 0.0f;
    }
    setDirection(toDirection(m_moveCoords));

    // move
    m_sprite.move(m_moveCoords * delta * 200.0f);
  }
  m_animation.direction(getDirection());
  m_animation.update(delta);
}

void Cat::drawObject(sf::RenderWindow& target) { target.draw(m_sprite); }

void Cat::collideWithFish() {
  /*m_isMoving = false;
  if (getDirection() == Direction::Right) {
    setDirection(Direction::AttackRight);
  } else {
    setDirection(Direction::AttackLeft);
  }*/
}
