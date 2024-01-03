#pragma once

#pragma warning(push)
#pragma warning(disable : 26495 26813)
#pragma warning(pop)

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <stdexcept>
#include <vector>

#include "AnimationData.h"

class Resources {
 public:
  enum Objects {
    Cat,
    Fish,
    Fire,
    Coin,
    Puddle,
    Bubble,
    Food,
    Max,
  };

  enum Sound_ID {
    BubblePop,
    Click,
    CoinTaken,
    FireBurn,
    FishFlop,
    Lost,
    NextLevel,
    WaterSplash,
    Stab,
    Sword,
    Win,
    Maxx
  };

  static Resources& instance();

  Resources(const Resources&) = delete;
  Resources& operator=(const Resources&) = delete;
  ~Resources() = default;

  const sf::Texture& texture() const { return m_texture; }
  const AnimationData& animationData(Objects object) { return m_data[object]; }

  void playSound(Sound_ID id);

 private:
  Resources();
  std::string m_soundNames[11] = {"bubble.wav",
                                  "click.wav",
                                  "coins.wav",
                                  "fire.wav",
                                  "fish.wav",
                                  "lose.wav",
                                  "next_level.wav",
                                  "splash.wav",
                                  "stab.wav"
                                  "sword.wav",
                                  "win.wav"};

  sf::SoundBuffer m_buffers[11];
  sf::Sound m_sounds[11];

  sf::Texture m_texture;
  std::vector<AnimationData> m_data;
};
