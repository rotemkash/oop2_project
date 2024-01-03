#include "MovingObject.h"

MovingObject::MovingObject(sf::Sprite& sprite, float speed)
    : Object(sprite), m_speed(speed) {}

void MovingObject::setSpeed(float speed) { m_speed = speed; }

float MovingObject::getSpeed() const { return m_speed; }

void MovingObject::setDirection(Direction newDir) { m_dir = newDir; }

Direction MovingObject::getDirection() const { return m_dir; }

