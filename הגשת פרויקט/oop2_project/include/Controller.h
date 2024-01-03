#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Cat.h"
#include "Fish.h"
#include "Level.h"
#include "LevelManager.h"
#include "MainMenu.h"
#include "MovingObject.h"
#include "Object.h"
#include "Platform.h"
#include "StatusBar.h"

const float SCREEN_SIZE = 800.f;

class Controller {
 private:
  bool m_gameRunning = true;
  sf::RenderWindow m_window;
  sf::View m_view;
  sf::View m_view2;
  sf::Texture m_playerTexture;
  sf::Texture m_backgroundTexture;
  LevelManager m_lvl;
  StatusBar m_statusBar;
  bool m_mainMenuDisplayed;
  MainMenu m_mainMenu;
  bool m_helpPageDisplayed;
  int buttonId = -1;
  int m_levelNum = 1;

 public:
  Controller();

  void run();
};
