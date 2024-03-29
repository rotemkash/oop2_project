
#include "Animation.h"

#include <iostream>

#include "Resources.h"
const auto AnimationTime = sf::seconds(0.1f);

Animation::Animation(const AnimationData& data, Direction dir,
                     sf::Sprite& sprite)
    : m_data(data), m_dir(dir), m_sprite(sprite) {
  m_sprite.setTexture(Resources::instance().texture());
  update();
}

void Animation::direction(Direction dir) {
  if (m_dir == dir || dir == Direction::Stay) {
    return;
  }

  m_dir = dir;
  update();
}

void Animation::update(float delta) {
  m_elapsed += delta;
  if (m_elapsed >= AnimationTime.asSeconds()) {
    m_elapsed -= AnimationTime.asSeconds();
    ++m_index;
    m_index %= m_data.m_data.find(m_dir)->second.size();
    update();
  }
}

void Animation::nextAnimation() {
  std::cout << "NEXT STAGE\n";
  ++m_index;
  m_index %= m_data.m_data.find(m_dir)->second.size();
  update();
}

void Animation::update() {
  m_sprite.setTextureRect(m_data.m_data.find(m_dir)->second[m_index]);
}
