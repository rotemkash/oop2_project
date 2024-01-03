#include "LevelManager.h"

LevelManager::LevelManager() { readNextLevel(1); }

void LevelManager::drawLevel(sf::RenderWindow& window, sf::View& view) {
  for (auto i = m_movingObjects.begin(); i != m_movingObjects.end(); i++) {
    Fish* fishRef = dynamic_cast<Fish*>((*i).get());
    if (fishRef) {
      view.setCenter(fishRef->getObjectPos() + sf::Vector2f(0.f, -100.f));
    }
    (*i)->drawObject(window);
  }

  for (auto i = m_staticObjects.begin(); i != m_staticObjects.end(); i++) {
    (*i)->drawObject(window);
  }
}

// STL-like algorithm to run over all pairs
template <typename FwdIt1, typename FwdIt2, typename Fn>
void for_each_pair(FwdIt1 firstBegin, FwdIt1 firstEnd, FwdIt2 secondBegin,
                   FwdIt2 secondEnd, Fn fn) {
  for (; firstBegin != firstEnd; ++firstBegin)
    for (auto second = secondBegin; second != secondEnd; ++second)
      fn(*firstBegin, *second);
}

bool collide(Object& a, Object& b) {
  return a.getObjBounds().intersects(b.getObjBounds());
}

void LevelManager::moveObjects(float delta, sf::Event event, StatusBar& bar) {
  Fish* fishptr = nullptr;
  for (auto obj = m_movingObjects.begin(); obj < m_movingObjects.end(); obj++) {
    fishptr = dynamic_cast<Fish*>((*obj).get());
    if (fishptr) {
      fishptr->direction(event);
      fishptr->updateStatusBar(bar);
      if (fishptr->getState() == 1) {
      }
      std::cout << fishptr->getObjectPos().x << ", "
                << fishptr->getObjectPos().y << std::endl;
    }
    (*obj)->move(delta);
  }

  for_each_pair(m_movingObjects.begin(), m_movingObjects.end(),
                m_movingObjects.begin() + 1, m_movingObjects.end(),
                [](auto& a, auto& b) {
                  if (collide(*a, *b)) {
                    processCollision(*a, *b);
                  }
                });

  for_each_pair(m_movingObjects.begin(), m_movingObjects.end(),
                m_staticObjects.begin(), m_staticObjects.end(),
                [](auto& a, auto& b) {
                  if (collide(*a, *b)) {
                    processCollision(*a, *b);
                  }
                });

    Coin* coinPtr = nullptr;
  for (auto obj = m_staticObjects.begin(); obj != m_staticObjects.end(); obj++) {
    coinPtr = dynamic_cast<Coin*>((*obj).get());

    if (coinPtr) {
      if (coinPtr->isEaten()) {
        m_staticObjects.erase(obj);
        break;
      }
    }

  }
}

void LevelManager::readNextLevel(int lvl) {
  if (!m_movingObjects.empty()) {
    m_movingObjects.clear();
  }

  if (!m_staticObjects.empty()) {
    m_staticObjects.clear();
  }

  m_file.open("Level_" + std::to_string(lvl) + ".txt");

  char type;
  float posX = 0.0f, posY = 0.0f;

  while (!m_file.eof()) {
    m_file >> type >> posX >> posY;
    std::cout << type << " " << posX << " " << posY << std::endl;
    switch (type) {
      case 'P':
        m_staticObjects.push_back(
            std::move(std::make_unique<Platform>(posX, posY)));
        break;
      case 'C':
        m_movingObjects.push_back(std::move(std::make_unique<Cat>(posX, posY)));
        break;
      case 'F':
        m_movingObjects.push_back(
            std::move(std::make_unique<Fish>(posX, posY)));
        break;
      case '$':
        m_staticObjects.push_back(
            std::move(std::make_unique<Coin>(posX, posY)));
        break;
      case 'W':
        m_staticObjects.push_back(
            std::move(std::make_unique<Puddle>(posX, posY)));

      default:
        break;
    }
  }
}