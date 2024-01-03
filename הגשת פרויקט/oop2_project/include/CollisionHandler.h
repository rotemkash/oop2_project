#pragma once

#include <iostream>
#include <typeinfo>

#include "Object.h"

struct UnknownCollision : public std::runtime_error {
  UnknownCollision(Object &a, Object &b)
      : std::runtime_error(std::string("Unknown collision of ") +
                           typeid(a).name() + " and " + typeid(b).name()) {}
};

void processCollision(Object &obj1, Object &obj2);