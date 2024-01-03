#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Bubble.h"

class StatusBar {
 private:
  std::vector<std::unique_ptr<Bubble>> m_bubbles;
  float m_timeLeft;
  float m_elapsed = 0.0f;
  int m_scoreNum;
  int m_lvlNum;
  int m_livesNum;

  sf::Font m_font;
  sf::Text m_scoreTxt;
  sf::Text m_lvlTxt;
  sf::Text m_livesTxt;
  sf::Texture m_livesTexture;
  sf::Sprite m_livesSprite;
  sf::RectangleShape m_background;

 public:
  StatusBar(float time, int score, int lvl, int lives);

  void drawBar(sf::RenderWindow &window, float deltaTime);

  void setScore(int score);

  void setlives(int lives);

  int getScore() const;

  void setLevel(int level);

  int getLevel() const;
};