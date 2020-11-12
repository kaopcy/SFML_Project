#include "Background_move.h"
Background_move::Background_move(sf::Texture *texture)
{
	backgroundmove.setTexture(*texture);
}
Background_move::~Background_move()
{
}
void Background_move::draw(sf::RenderWindow& window)
{
	window.draw(backgroundmove);
}
void Background_move::background_update(float deltatime)
{
    backgroundmove.setTextureRect(sf::IntRect((int)i, 0, 1920, 1080));
    totaltime += deltatime;
    if (totaltime >= .01f)
    {
        totaltime -= .01f;
        i += 3;
    }
    /*if (counttime - totaltime > 0.01f)
    {
        totaltime = counttime;
        i += 3;
    }*/
    if (i > 3840)
    {
        i = 0;
    }
}