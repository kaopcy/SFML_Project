#include "movement.h"
#include "animation.h"
movement::movement(sf::Texture *texture, sf::Vector2u imageCount, float switchTime) :
    animation(*texture , imageCount, switchTime)
{
    body.setTexture(texture);
    body.setPosition(750, 750);
}
void movement::update(int millis)
{
    sf::Vector2f move(0.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        move.x--;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        move.x++;
    }
    animation.update(row, millis);
    body.setTextureRect(animation.playerRect);
    body.move(move);
}