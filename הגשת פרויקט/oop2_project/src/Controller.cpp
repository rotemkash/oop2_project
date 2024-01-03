#include "Controller.h"

Controller::Controller()
    : m_window(sf::VideoMode(SCREEN_SIZE, SCREEN_SIZE), "Fish To Freedom",
               sf::Style::Close | sf::Style::Titlebar),
      m_view(sf::FloatRect(0.0f, 0.0f, SCREEN_SIZE, SCREEN_SIZE)),
      m_view2(sf::FloatRect(0.0f, 0.0f, SCREEN_SIZE, SCREEN_SIZE)),
      m_mainMenuDisplayed(true),
      m_helpPageDisplayed(false),
      m_statusBar(196.0f, 0, 1, 3) {
  m_backgroundTexture.loadFromFile("background.png");
  m_window.setFramerateLimit(60);
}

void Controller::run() {
  auto gameClock = sf::Clock();
  sf::Time deltaTime;
  sf::RectangleShape backgroundSprite;
  backgroundSprite.setSize({8000.0f, 2000.0f});
  backgroundSprite.setTexture(&m_backgroundTexture);
  backgroundSprite.setPosition(-400.0f, -1700.0f);
  auto event = sf::Event{};

  MainMenu mainMenu;

  while (m_window.isOpen()) {
    deltaTime = gameClock.restart();

    while (m_window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          m_window.close();
          break;
        case sf::Event::MouseButtonReleased:

          if (m_mainMenuDisplayed) {
            buttonId = mainMenu.buttonPressed(&m_window, event.mouseButton);
            if (buttonId == NEW_GAME) {
              m_mainMenuDisplayed = false;
            } else if (buttonId == HELP) {
              m_mainMenuDisplayed = false;
              m_helpPageDisplayed = true;
              mainMenu.drawHelpPage(&m_window);
              m_window.setView(m_view);
            } else if (buttonId == EXIT) {
              m_window.close();
            }
          }

          break;
        case sf::Event::MouseMoved:
          break;
        case sf::Event::KeyPressed:
          if (event.key.code == sf::Keyboard::Escape) {
            if (buttonId == HELP) {
              m_helpPageDisplayed = false;
              m_mainMenuDisplayed = true;
              buttonId = MAIN_MENU;
            } else {
              m_window.close();
            }
          }
          break;
      }
    }

    m_window.clear(sf::Color(128, 128, 128));
    m_window.setView(m_view);

    m_window.draw(backgroundSprite);

    if (m_mainMenuDisplayed) {
      mainMenu.drawMainMenu(&m_window);
    } else if (m_helpPageDisplayed) {
      mainMenu.drawHelpPage(&m_window);
    } else {
      if (m_statusBar.getLevel() != m_levelNum) {
        m_lvl.readNextLevel(m_levelNum);
        m_levelNum = m_statusBar.getLevel();
        continue;
      }
      m_lvl.moveObjects(deltaTime.asSeconds(), event, m_statusBar);
      m_lvl.drawLevel(m_window, m_view);

      m_window.setView(m_view2);
      m_statusBar.drawBar(m_window, deltaTime.asSeconds());
    }

    m_window.display();
  }
}
