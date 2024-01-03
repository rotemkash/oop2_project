#pragma once

#include <SFML/Graphics.hpp>

class DynamicBody {
 private:
  bool m_isJumping = false;
  bool m_isFalling = false;
  bool m_deAccelerate = false;
  bool m_onFloor = true;
  sf::Vector2f m_position;
  sf::Vector2f m_directionVec = sf::Vector2f(0.0f, 0.0f);
  float m_velocityX;  
  float m_velocityY; 
  float m_gravityY;  
  float m_frictionX;  


 public:
  DynamicBody(sf::Vector2f position, float velocityX, float velocityY,
              float accelerationY, float accelerationX);


  void moveBody(float delta);

  void setPos(sf::Vector2f pos);
  sf::Vector2f GetPos() const;

  void accelerate();
  void deAccelerate();

  void setJump();
  void resetJump();
  bool isJumping() const;

  void setFalling();
  void resetFalling();
  bool isFalling() const;

  void goRight();
  void stayX();
  void goLeft();

  void goUp();
  void stayY();
  void goDown();

  void setFloor();
  void resetFloor();


  sf::Vector2f getDirection() const;
};