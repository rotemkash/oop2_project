#include "Direction.h"

#include <stdexcept>

// Direction opposite(Direction dir) {
//   switch (dir) {
//      case Direction::JumpLeft:
//       return Direction::Down;
//     case Direction::Down:
//       return Direction::JumpLeft;
//     case Direction::Right:
//       return Direction::Left;
//     case Direction::Left:
//       return Direction::Right;
//     case Direction::Stay:
//       return Direction::Stay;
//   }
//   throw std::runtime_error("Unknown direction");
// }

sf::Vector2f toVector(sf::Keyboard::Key keyCode) {
	switch (keyCode) {
	case sf::Keyboard::Up:
		return { 0, -1 };
		/*case Direction::Down:
		  return {0, 1};*/
	case sf::Keyboard::Right:
		return { 1, 0 };
	case sf::Keyboard::Left:
		return { -1, 0 };
	default:
		return { 0, 0 };
	}
	// throw std::runtime_error("Unknown direction");
}

Direction toDirection(sf::Vector2f vec) {
	/* if (vec == sf::Vector2f(0.0f, 0.0f)) {
	 } else*/
	if (vec == sf::Vector2f(0.0f, -1.0f) || vec == sf::Vector2f(1.0f, -1.0f) ||
		vec == sf::Vector2f(0.0f, 1.0f) || vec == sf::Vector2f(1.0f, 1.0f)) {
		return Direction::JumpRight;
	}
	/*else if (vec == sf::Vector2f(1.0f, -1.0f)) {
		return Direction::JumpRight;
	}*/
	else if (vec == sf::Vector2f(-1.0f, -1.0f) || vec == sf::Vector2f(-1.0f, 1.0f)) {
		return Direction::JumpLeft;
	}
	else if (vec == sf::Vector2f(1.0f, 0.0f)) {
		return Direction::Right;
	}
	else if (vec == sf::Vector2f(-1.0f, 0.0f)) {
		return Direction::Left;
	}
	else {
		return Direction::Stay;
	}
}

//-1, -1    -1, 0    -1, 1
// 0, -1    0, 0    0, 1
// 1, -1    1, 0    1,-1
// 

