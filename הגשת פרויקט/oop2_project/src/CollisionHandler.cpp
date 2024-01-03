#include "CollisionHandler.h"

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <typeindex>
#include <typeinfo>

#include "Cat.h"
#include "Coin.h"
#include "Fire.h"
#include "Fish.h"
#include "Platform.h"
#include "Puddle.h"

namespace {
// Fish
void fishPlatform(Object& fish, Object& platform) {
  // TODO:
  // Fish& fish = dynamic_cast<Fish&>(fish);
  // Platform& platform = dynamic_cast<Platform&>(platform);
  // or:
  // Fish& fish = static_cast<Fish&>(fish);
  // Platform& platform = static_cast<Platform&>(platform);

  Fish& fishRef = dynamic_cast<Fish&>(fish);
  Platform& platformRef = dynamic_cast<Platform&>(platform);

  sf::FloatRect intersection;
  Resources::instance().playSound(Resources::FishFlop);
  if (fishRef.getObjBounds().intersects(platformRef.getObjBounds(),
                                        intersection)) {
    float overlapX = intersection.width;
    float overlapY = intersection.height;

    if (overlapX > overlapY) {
      if (fishRef.getObjBounds().top < platformRef.getObjBounds().top) {
        fishRef.topCollision();
        std::cout << "collided from top\n";
      } else {
        fishRef.bottomCollision();
        std::cout << "collided from bottom\n";
      }
    } else {
      if (fishRef.getObjBounds().left < platformRef.getObjBounds().left) {
        std::cout << "collided from left\n";
        fishRef.leftCollision();

      } else {
        fishRef.rightCollision();
        std::cout << "collided from right\n";
      }
    }
  }
}
void fishPuddle(Object& fish, Object& puddle) {
  Fish& fishRef = dynamic_cast<Fish&>(fish);
  fishRef.setState(1);
  fishRef.nextLevel();
}

void fishCoin(Object& fish, Object& coin) {
  Resources::instance().playSound(Resources::CoinTaken);
  Fish& fishRef = dynamic_cast<Fish&>(fish);
  Coin& coinRef = dynamic_cast<Coin&>(coin);
  fishRef.takeCoin();
  coinRef.gotEaten();
}
void fishFire(Object& fish, Object& fire) {}
void fishCat(Object& fish, Object& cat) {
  Fish& fishRef = dynamic_cast<Fish&>(fish);
  Cat& catRef = dynamic_cast<Cat&>(cat);
  Resources::instance().playSound(Resources::Sword);
  catRef.collideWithFish();
  fishRef.collideWithCat();
  std::cout << "fishCat\n";
  //
}

// Cat
void catPlatform(Object& cat, Object& Platform) {}
void catPuddle(Object& cat, Object& puddle) {}
void catCoin(Object& cat, Object& coin) {}
void catFire(Object& cat, Object& fire) {}
void catCat(Object& cat1, Object& cat2) {}

// Platform
void platformPlatform(Object& platform, Object& Platform) {}
void platformPuddle(Object& platform, Object& puddle) {}
void platformCoin(Object& platform, Object& coin) {}
void platformFire(Object& platform, Object& fire) {}

// Fire
void firePuddle(Object& fire, Object& puddle) {}
void fireCoin(Object& fire, Object& coin) {}
void fireFire(Object& fire1, Object& fire2) {}

// Coin
void coinPuddle(Object& coin, Object& puddle) {}
void coinCoin(Object& coin1, Object& coin2) {}

// Puddle
void puddlePlatform(Object& puddle, Object& platform) {}

//=======-SECONDARY-==============
void coinFish(Object& coin, Object& fish) { fishCoin(fish, coin); }

void catFish(Object& cat, Object& fish) {
  std::cout << "catFish\n";
  fishCat(fish, cat);

  //
}
void platformFish(Object& platform, Object& fish) {}
void fireFish(Object& fire, Object& fish) {}
void puddleFish(Object& puddle, Object& fish) { fishPuddle(fish, puddle); }

void coinCat(Object& coin, Object& cat) {}
void platformCat(Object& platform, Object& cat) {}
void fireCat(Object& fire, Object& cat) {}
void puddleCat(Object& puddle, Object& cat) {}

void firePlatform(Object& fire, Object& Platform) {}
void coinPlatform(Object& coin, Object& Platform) {}

void coinFire(Object& coin, Object& fire) {}
void puddleFire(Object& puddle, Object& fire) {}

void puddleCoin(Object& puddle, Object& coin) {}

//---------------------

using HitFunctionPtr = std::function<void(Object&, Object&)>;
using Key = std::pair<std::type_index, std::type_index>;
// pair
using HitMap = std::map<Key, HitFunctionPtr>;

HitMap initializeCollisionMap() {
  HitMap phm;
  phm[Key(typeid(Fish), typeid(Platform))] = &fishPlatform;
  phm[Key(typeid(Fish), typeid(Puddle))] = &fishPuddle;
  phm[Key(typeid(Fish), typeid(Coin))] = &fishCoin;
  phm[Key(typeid(Fish), typeid(Fire))] = &fishFire;
  phm[Key(typeid(Fish), typeid(Cat))] = &fishCat;

  phm[Key(typeid(Cat), typeid(Platform))] = &catPlatform;
  phm[Key(typeid(Cat), typeid(Puddle))] = &catPuddle;
  phm[Key(typeid(Cat), typeid(Coin))] = &catCoin;
  phm[Key(typeid(Cat), typeid(Fire))] = &catFire;
  phm[Key(typeid(Cat), typeid(Cat))] = &catCat;

  phm[Key(typeid(Platform), typeid(Platform))] = &platformPlatform;
  phm[Key(typeid(Platform), typeid(Puddle))] = &platformPuddle;
  phm[Key(typeid(Platform), typeid(Coin))] = &platformCoin;
  phm[Key(typeid(Platform), typeid(Fire))] = &platformFire;

  phm[Key(typeid(Fire), typeid(Puddle))] = &firePuddle;
  phm[Key(typeid(Fire), typeid(Coin))] = &fireCoin;
  phm[Key(typeid(Fire), typeid(Fire))] = &fireFire;

  phm[Key(typeid(Coin), typeid(Puddle))] = &coinPuddle;
  phm[Key(typeid(Coin), typeid(Coin))] = &coinCoin;

  phm[Key(typeid(Puddle), typeid(Platform))] = &puddlePlatform;

  //===-SECONDARY-==
  phm[Key(typeid(Coin), typeid(Fish))] = &coinFish;
  phm[Key(typeid(Cat), typeid(Fish))] = &catFish;
  phm[Key(typeid(Platform), typeid(Fish))] = &platformFish;
  phm[Key(typeid(Fire), typeid(Fish))] = &fireFish;
  phm[Key(typeid(Puddle), typeid(Fish))] = &puddleFish;

  phm[Key(typeid(Coin), typeid(Cat))] = &coinCat;
  phm[Key(typeid(Platform), typeid(Cat))] = &platformCat;
  phm[Key(typeid(Fire), typeid(Cat))] = &fireCat;
  phm[Key(typeid(Puddle), typeid(Cat))] = &puddleCat;

  phm[Key(typeid(Fire), typeid(Platform))] = &firePlatform;
  phm[Key(typeid(Coin), typeid(Platform))] = &coinPlatform;

  phm[Key(typeid(Coin), typeid(Fire))] = &coinFire;
  phm[Key(typeid(Puddle), typeid(Fire))] = &puddleFire;

  phm[Key(typeid(Puddle), typeid(Coin))] = &puddleCoin;
  //
  return phm;
}

HitFunctionPtr lookup(const std::type_index& class1,
                      const std::type_index& class2) {
  static HitMap collisionMap = initializeCollisionMap();
  auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
  if (mapEntry == collisionMap.end()) {
    return nullptr;
  }

  return mapEntry->second;
}

}  // end namespace

void processCollision(Object& obj1, Object& obj2) {
  auto phf = lookup(typeid(obj1), typeid(obj2));
  if (!phf) {
    // throw UnknownCollision(obj1, obj2);
  } else {
    phf(obj1, obj2);
  }
}

