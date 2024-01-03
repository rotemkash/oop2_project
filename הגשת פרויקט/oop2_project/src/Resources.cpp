#include "Resources.h"

namespace {
AnimationData catData() {
  const auto size = sf::Vector2i(85, 100);
  const auto initSpace = sf::Vector2i(123, 1);  // first img position

  auto cat = AnimationData{};
  auto currentStart = initSpace;

  auto nextStart = [&]() {
    currentStart.y += size.y;
    return currentStart;
  };

  cat.m_data[Direction::Right].emplace_back(currentStart, size);
  for (size_t i = 1; i < 8; i++) {
    cat.m_data[Direction::Right].emplace_back(nextStart(), size);
  }

  currentStart.x += size.x;
  currentStart.y = initSpace.y;
  cat.m_data[Direction::Left].emplace_back(currentStart, size);
  for (size_t i = 1; i < 8; i++) {
    cat.m_data[Direction::Left].emplace_back(nextStart(), size);
  }

  currentStart.x += size.x;
  currentStart.y = initSpace.y;
  cat.m_data[Direction::AttackRight].emplace_back(currentStart, size);
  for (size_t i = 1; i < 4; i++) {
    cat.m_data[Direction::AttackRight].emplace_back(nextStart(), size);
  }

  currentStart.x += size.x;
  currentStart.y = initSpace.y;
  cat.m_data[Direction::AttackLeft].emplace_back(currentStart, size);
  for (size_t i = 1; i < 4; i++) {
    cat.m_data[Direction::AttackLeft].emplace_back(nextStart(), size);
  }

  return cat;
}

AnimationData fishData() {
  const auto size = sf::Vector2i(120, 60);
  const auto initSpace = sf::Vector2i(1, 1);    // first img position
  const auto middleSpace = sf::Vector2i(0, 0);  // jump to next img

  auto fish = AnimationData{};
  auto currentStart = initSpace;

  auto nextStart = [&]() {
    currentStart += middleSpace;
    currentStart.y += size.y;
    return currentStart;
  };

  fish.m_data[Direction::Stay].emplace_back(currentStart, size);
  fish.m_data[Direction::Right].emplace_back(nextStart(), size);
  fish.m_data[Direction::Right].emplace_back(nextStart(), size);
  fish.m_data[Direction::Left].emplace_back(nextStart(), size);
  fish.m_data[Direction::Left].emplace_back(nextStart(), size);

  fish.m_data[Direction::JumpRight].emplace_back(nextStart(), size);
  fish.m_data[Direction::JumpRight].emplace_back(nextStart(), size);
  fish.m_data[Direction::JumpLeft].emplace_back(nextStart(), size);
  fish.m_data[Direction::JumpLeft].emplace_back(nextStart(), size);
  return fish;
}

AnimationData fireData() {
  const auto size = sf::Vector2i(50, 70);
  const auto initSpace = sf::Vector2i(463, 1);  // first img position
  const auto middleSpace = sf::Vector2i(0, 0);  // jump to next img

  auto fire = AnimationData{};
  auto currentStart = initSpace;

  auto nextStart = [&]() {
    currentStart += middleSpace;
    currentStart.y += size.y;
    return currentStart;
  };

  fire.m_data[Direction::Stay].emplace_back(currentStart, size);
  for (size_t i = 1; i < 8; i++) {
    fire.m_data[Direction::Stay].emplace_back(nextStart(), size);
  }
  return fire;
}

AnimationData coinData() {
  const auto size = sf::Vector2i(30, 30);
  const auto initSpace = sf::Vector2i(513, 1);  // first img position
  const auto middleSpace = sf::Vector2i(0, 0);  // jump to next img

  auto coin = AnimationData{};
  auto currentStart = initSpace;

  auto nextStart = [&]() {
    currentStart += middleSpace;
    currentStart.y += size.y;
    return currentStart;
  };

  coin.m_data[Direction::Stay].emplace_back(currentStart, size);
  for (size_t i = 1; i < 7; i++) {
    coin.m_data[Direction::Stay].emplace_back(nextStart(), size);
  }
  return coin;
}

AnimationData bubbleData() {
  const auto size = sf::Vector2i(50, 49);
  const auto initSpace = sf::Vector2i(543, 1);  // first img position
  const auto middleSpace = sf::Vector2i(0, 0);  // jump to next img

  auto bubble = AnimationData{};
  auto currentStart = initSpace;

  auto nextStart = [&]() {
    currentStart += middleSpace;
    currentStart.y += size.y;
    return currentStart;
  };

  bubble.m_data[Direction::Stay].emplace_back(currentStart, size);
  for (size_t i = 0; i < 8; i++) {
    bubble.m_data[Direction::Stay].emplace_back(nextStart(), size);
  }
  return bubble;
}

}  // namespace

Resources& Resources::instance() {
  static Resources instance;
  return instance;
}

void Resources::playSound(Sound_ID id) {
  if (m_sounds[int(id)].getStatus() != sf::Sound::Playing) {
    m_sounds[int(id)].play();
  }
}

Resources::Resources() : m_data(Max) {
  if (!m_texture.loadFromFile("sprites.png")) {
    throw std::runtime_error("Can't load file");
  }

  for (int i = 0; i < 11; i++) {
    m_buffers[i].loadFromFile(m_soundNames[i]);
  }

  /* matches each sound with it's own buffer*/
  for (int i = 0; i < 11; i++) {
    m_sounds[i].setBuffer(m_buffers[i]);
  }

  m_data[Fish] = fishData();
  m_data[Cat] = catData();
  m_data[Fire] = fireData();
  m_data[Coin] = coinData();
  m_data[Bubble] = bubbleData();
}
