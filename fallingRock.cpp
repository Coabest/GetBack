#include "fallingRock.hpp"

fallingRock::fallingRock()
{
  size = 1 + rand()%5;
  rect.setScale(size, size);
  rect.setPosition( 100 + rand()%700, rand()%300 - 300);

  texture.loadFromFile("rollingRock.png");

  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect( 0, 0, 16, 16));
  sprite.setScale(rect.getScale());
  
}

void fallingRock::update()
{
  sprite.setPosition(rect.getPosition());
  sprite.setRotation(rect.getRotation());
  sprite.setScale(rect.getScale());

  rect.move(0, moveSpeed);
  rect.rotate(8);
  if ( rect.getPosition().y > 550 )
  {
    moveSpeed += rand()%4 - 2;
    if (moveSpeed < moveSpeed - 5 || moveSpeed > moveSpeed + 10)
      moveSpeed = baseMoveSpeed;

    size = 1 + rand()%5;
    rect.setScale( size, size );
    rect.setPosition( 50 + rand()%700, -1 /*rand()%300 - */);
  }

}