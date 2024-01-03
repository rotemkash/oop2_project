
#pragma once

#include <optional>

#include "Animation.h"
#include "DynamicBody.h"
#include "MovingObject.h"
#include "Resources.h"
#include "StatusBar.h"

constexpr auto PacmanSpeed = 200.f;

class Fish : public MovingObject {
 public:
  Fish(float x, float y);

  void move(float delta) override;

  void direction(sf::Event event);

  void topCollision();

  void rightCollision();

  void bottomCollision();

  void leftCollision();

  void drawObject(sf::RenderWindow& target) override;

  int getLives() const;

  void collideWithCat();

  void takeCoin();

  void updateStatusBar(StatusBar& bar);

  void setState(int state);

  int getState() const;

  void nextLevel();

 private:
  int m_lives = 3;
  int m_score = 0;
  float m_elapsed = 0.0f;
  int m_state = 0;
  int m_level = 1;
  sf::Sprite m_sprite;
  Animation m_animation;
  DynamicBody m_body;
};
