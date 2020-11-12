#include "background.h"
Background::Background()
{
	btexture.loadFromFile("background.jpg");
	backgroundmove.setTexture(btexture);
}
void Background::draw(sf::RenderWindow& window)
{
	window.draw(backgroundmove);
}