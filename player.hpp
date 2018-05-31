#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

#include "entity.hpp"

class player: public entity
{
public:
  int direction = 1; // 1 = Up, 2 = Down, 3 = Right, 4 = Left
  int moveSpeed = 4;
  int frameCounter = 0; 
  int walkingAnimationFrame = 1;

  player();
  void update();

};
#endif
