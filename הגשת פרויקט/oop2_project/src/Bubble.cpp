#include "Bubble.h"

Bubble::Bubble(float x, float y, int stage)
    : StaticObject(m_sprite),
      m_animation(Resources::instance().animationData(Resources::Bubble),
                  Direction::Stay, m_sprite),
      m_stage(stage) {
  setObjectPos({x, y});
}

void Bubble::drawObject(sf::RenderWindow& target) { target.draw(m_sprite); }

void Bubble::decreaseStage() {
  --m_stage;
  m_animation.nextAnimation();
}

int Bubble::getStage() const { return m_stage; }

void Bubble::setStage(int stage) { m_stage = stage; }
