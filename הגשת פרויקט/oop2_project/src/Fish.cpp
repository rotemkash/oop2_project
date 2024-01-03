#include "Fish.h"

#include <iostream>
namespace {
std::optional<Direction> toDirection(sf::Keyboard::Key key) {
  switch (key) {
    case sf::Keyboard::Left:
      return Direction::Left;
    case sf::Keyboard::Right:
      return Direction::Right;
    case sf::Keyboard::Up:
      return Direction::Jump;  // Up -> Jump
    case sf::Keyboard::Down:
      return Direction::Down;
    case sf::Keyboard::Space:
      return Direction::Stay;
  }
  return {};
}
}  // namespace

Fish::Fish(float x, float y)
    : MovingObject(m_sprite, 20.0f),
      m_animation(Resources::instance().animationData(Resources::Fish),
                  Direction::Right, m_sprite),
      m_body(sf::Vector2f(0.0f, 0.0f), 150.0f, 350.0f, 3.0f, 2.0f) {
  m_sprite.setOrigin(120.f / 2.f, 60.f / 2.f);
  m_sprite.setPosition(x, y);
}

void Fish::move(float delta) {
  m_elapsed += delta;
  if (getDirection() == Direction::Stay) {
    return;
  }

  m_body.moveBody(delta);
  m_body.resetFloor();

  m_sprite.setPosition(m_body.GetPos());

  m_animation.update(delta);
}

void Fish::direction(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    switch (event.key.code) {
      case sf::Keyboard::Left:
        m_body.goLeft();
        m_body.accelerate();
        break;
      case sf::Keyboard::Right:
        m_body.goRight();
        m_body.accelerate();
        break;
      case sf::Keyboard::Up:
        if (!m_body.isJumping()) {
          m_body.goUp();
          m_body.setJump();
          m_body.resetFalling();
          m_body.resetFloor();
        }
        break;
      default:
        break;
    }
  } else if (event.type == sf::Event::KeyReleased) {
    switch (event.key.code) {
      case sf::Keyboard::Left:
      case sf::Keyboard::Right:
        m_body.deAccelerate();
        break;

      default:
        break;
    }
  }
  setDirection(toDirection(m_body.getDirection()));
  m_animation.direction(toDirection(m_body.getDirection()));
}

void Fish::topCollision() {
  m_body.stayY();
  m_body.resetFalling();
  m_body.resetJump();
  m_body.setFloor();
}

void Fish::rightCollision() { m_body.stayX(); }

void Fish::bottomCollision() {
  m_body.goDown();
  m_body.setFalling();
  m_body.resetJump();
  m_body.resetFloor();
}

void Fish::leftCollision() { m_body.stayX(); }

void Fish::drawObject(sf::RenderWindow& target) { target.draw(m_sprite); }

int Fish::getLives() const { return m_lives; }

void Fish::collideWithCat() {
  if (m_elapsed > 5.0f) {
    m_elapsed = 0.0f;
    m_lives--;
    m_body.goUp();
    m_body.setJump();
    m_body.resetFalling();
    m_body.resetFloor();
  }
}

void Fish::takeCoin() { m_score += 3; }

void Fish::updateStatusBar(StatusBar& bar) {
  bar.setlives(m_lives);
  bar.setScore(m_score);
  bar.setLevel(m_level);
}

void Fish::setState(int state) { m_state = state; }

int Fish::getState() const { return m_state; }

void Fish::nextLevel() { m_level++; }
