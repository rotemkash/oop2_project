#pragma once
#include "Animation.h"
#include "Resources.h"
#include "StaticObject.h"

class Bubble : public StaticObject {
 private:
  sf::Sprite m_sprite;
  Animation m_animation;
  sf::Time m_tick = sf::seconds(3.0f);
  int m_stage;
  bool m_popped = false;

 public:
  Bubble(float x, float y, int stage);

  void drawObject(sf::RenderWindow& target) override;

  void decreaseStage();

  int getStage() const;

  void setStage(int stage);
};
