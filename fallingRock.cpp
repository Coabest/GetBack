#include "fallingRock.hpp"

fallingRock::fallingRock()
{
  size = 2 + rand()%4;
  rect.setScale(size, size);
  rect.setPosition( 960 + rand()%420, 420 );

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
  rect.rotate(10);
  if ( rect.getPosition().y > 800 )
  {
    moveSpeed += rand()%4 - 2;
    if (moveSpeed < moveSpeed - 5 || moveSpeed > moveSpeed + 10)
      moveSpeed = baseMoveSpeed;

    size = 2 + rand()%4;
    rect.setScale( size, size );
    rect.setPosition( 960 + rand()%420, 420 );
  }

}