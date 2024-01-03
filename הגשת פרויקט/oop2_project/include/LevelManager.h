#pragma once

#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

#include "Cat.h"
#include "StatusBar.h"
#include "Coin.h"
#include "Puddle.h"
#include "CollisionHandler.h"
#include "Fish.h"
#include "MovingObject.h"
#include "Object.h"
#include "Platform.h"
#include "StaticObject.h"

class LevelManager {
 private:
  std::vector<std::unique_ptr<MovingObject>> m_movingObjects;
  std::vector<std::unique_ptr<StaticObject>> m_staticObjects;

  std::ifstream m_file;

 public:
  LevelManager();

  void drawLevel(sf::RenderWindow &window, sf::View &view);

  void moveObjects(float delta, sf::Event event, StatusBar& bar);

  void readNextLevel(int lvl);
  //
  //
};