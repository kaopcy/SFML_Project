#include "Background_move.h"
Background_move::Background_move(sf::Texture *texture)
{
    btexture.loadFromFile("Background/Background.jpg");
	backgroundmove.setTexture(btexture);
    stopbackgroundmove.setTexture(btexture);
    stopbackgroundmove.setColor(sf::Color::Red);
}
Background_move::~Background_move()
{
}
void Background_move::draw(sf::RenderWindow& window, bool& sharingan)
{
    if (!sharingan)
    {
	    window.draw(backgroundmove);
    }
    else
    {
        window.draw(stopbackgroundmove);
    }
}
void Background_move::background_update(float deltatime , bool &sharingan )
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