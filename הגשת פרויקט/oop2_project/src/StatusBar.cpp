#include "StatusBar.h"

StatusBar::StatusBar(float time, int score, int lvl, int lives)
    : m_timeLeft(time), m_scoreNum(score), m_lvlNum(lvl), m_livesNum(lives) {
  if (!m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf")) {
    throw std::exception("FAILED TO READ FONT\n");
  }
  time = std::min(196.0f, time);

  for (float i = 0; i < time / 28; i++) {
    m_bubbles.push_back(std::make_unique<Bubble>(i * 50.0f, 10.0f, 8));
  }  // 210.0f

  m_livesTxt = sf::Text(std::to_string(m_livesNum), m_font, 20);
  m_livesTxt.setPosition(450.0f, 20.0f);

  m_scoreTxt = sf::Text("Score: " + std::to_string(m_scoreNum), m_font, 20);
  m_scoreTxt.setPosition(550.0f, 20.0f);

  m_lvlTxt = sf::Text("Level: " + std::to_string(m_lvlNum), m_font, 20);
  m_lvlTxt.setPosition(700, 20.0f);

  m_background.setSize(sf::Vector2f(800.0f, 80.0f));
  m_background.setFillColor(sf::Color::Black);
}

void StatusBar::drawBar(sf::RenderWindow& window, float deltaTime) {
  m_elapsed += deltaTime;
  window.draw(m_background);
  for (auto bubble = m_bubbles.rbegin(); bubble != m_bubbles.rend(); bubble++) {
    if (m_elapsed >= 1.0f) {
      if ((*bubble).get()->getStage() > 0) {
        (*bubble).get()->decreaseStage();
        m_elapsed = 0.0f;
      }
    }
    (*bubble).get()->drawObject(window);
  }

  window.draw(m_livesTxt);
  window.draw(m_scoreTxt);
  window.draw(m_lvlTxt);
}

void StatusBar::setScore(int score) {
  m_scoreTxt.setString("Score: " + std::to_string(score));
}

void StatusBar::setlives(int lives) {
  m_livesNum = lives;
  m_livesTxt.setString(std::to_string(lives));
}

int StatusBar::getScore() const { return m_livesNum; }

void StatusBar::setLevel(int level) { m_lvlNum = level; }

int StatusBar::getLevel() const { return m_lvlNum; }
