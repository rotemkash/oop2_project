#include "DynamicBody.h"

DynamicBody::DynamicBody(sf::Vector2f position, float velocityX,
                         float velocityY, float accelerationY,
                         float accelerationX)
    : m_position(position),
      m_velocityX(velocityX),
      m_velocityY(velocityY),
      m_gravityY(accelerationY),
      m_frictionX(accelerationX) {}

void DynamicBody::setPos(sf::Vector2f pos) { m_position = pos; }

// implement
void DynamicBody::moveBody(float delta) {
  if (m_isJumping) {
    m_velocityY -= m_gravityY;  // de-accelerate
  } else if (m_isFalling) {
    m_velocityY += m_gravityY;  // accelerate downwards
  } else if (!m_onFloor && m_position.y < 0) {
    setFalling();
    goDown();
  }

  if (m_velocityY <= 0 && m_isJumping && !m_onFloor) {
    goDown();   
    resetJump();  
    setFalling();
  }

  if (m_deAccelerate) {
    m_velocityX -= m_frictionX;
    if (m_velocityX <= 0) {
      m_velocityX = 150.0f;
      stayX();
    }
  }

  if (GetPos().y > 0.0f) {
    setPos(sf::Vector2f(GetPos().x, 0.0f));
    stayY();              
    m_velocityY = 350.0f;  
    resetFalling();
    resetJump();
  }

  m_position.x += m_directionVec.x * m_velocityX * delta;
  m_position.y += m_directionVec.y * m_velocityY * delta;
}

sf::Vector2f DynamicBody::GetPos() const { return m_position; }

void DynamicBody::accelerate() {
  m_deAccelerate = false;
  m_velocityX = 150.0f;
}

void DynamicBody::deAccelerate() { m_deAccelerate = true; }

void DynamicBody::setJump() { m_isJumping = true; }

void DynamicBody::resetJump() { m_isJumping = false; }

bool DynamicBody::isJumping() const { return m_isJumping; }

void DynamicBody::setFalling() { m_isFalling = true; }

void DynamicBody::resetFalling() { m_isFalling = false; }

bool DynamicBody::isFalling() const { return m_isFalling; }

void DynamicBody::goRight() { m_directionVec.x = 1.0f; }

void DynamicBody::stayX() { m_directionVec.x = 0.0f; }

void DynamicBody::goLeft() { m_directionVec.x = -1.0f; }

void DynamicBody::goUp() { m_directionVec.y = -1.0f; }

void DynamicBody::stayY() { m_directionVec.y = 0.0f; }

void DynamicBody::goDown() { m_directionVec.y = 1.0f; }

void DynamicBody::setFloor() {
  m_onFloor = true;
  m_velocityY = 350.0f;  
}

void DynamicBody::resetFloor() { m_onFloor = false; }

sf::Vector2f DynamicBody::getDirection() const { return m_directionVec; }
