#include "player.hpp"

player::player()
{
  rect.setSize(sf::Vector2f(40, 50));
  rect.setPosition(64,640);

  textureTest.loadFromFile("player-walking-2.png");
  texture.loadFromFile("player-walking-2.png");

  sprite.setTexture(texture);
  sprite.setOrigin(20,25);
  sprite.setTextureRect(sf::IntRect( 0, 0, 40, 50));
}

void player::update()
{
  sprite.setPosition(rect.getPosition());
  sprite.setScale(rect.getScale());

  if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W) || 
       sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
  {
    rect.move(0, -moveSpeed);
    sprite.setTextureRect( sf::IntRect( 40*walkingAnimationFrame, 150, 40, 50));
    direction = 1;
  }
  if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) || 
       sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
  {
    rect.move(0, moveSpeed);
    sprite.setTextureRect( sf::IntRect( 40*walkingAnimationFrame, 0, 40, 50));
    direction = 2;
  }
  if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) || 
       sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
  {
    rect.move(moveSpeed, 0);
    sprite.setTextureRect( sf::IntRect( 40*walkingAnimationFrame, 100, 40, 50));
    direction = 3;
  }
  if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) || 
       sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
  {
    rect.move(-moveSpeed, 0);
    sprite.setTextureRect( sf::IntRect( 40*walkingAnimationFrame, 50, 40, 50));
    direction = 4;
  }
  
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    // Change the spriteframe every 10 gameframes
    frameCounter++;
    if (frameCounter > 9)
      frameCounter = 0;
    if(frameCounter%10 == 0)
      walkingAnimationFrame++;

    if (walkingAnimationFrame > 3)
      walkingAnimationFrame = 0;
  }
  else
  {
    switch(direction)
    {
    case 1:
      sprite.setTextureRect( sf::IntRect( 0, 150, 40, 50));
      break;
    case 2:
      sprite.setTextureRect( sf::IntRect( 0, 0, 40, 50));
      break;
    case 3:
      sprite.setTextureRect( sf::IntRect( 0, 100, 40, 50));
      break;
    case 4:
      sprite.setTextureRect( sf::IntRect( 0, 50, 40, 50));
      break;
    }
  }
  
  
}