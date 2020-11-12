#pragma once
#include<SFML\Graphics.hpp>
#include "animation.h"
class movement
{
public:
	movement(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
	void update(int millis);
	void draw(sf::RenderWindow window);
private:
	sf::RectangleShape body; 
		animation animation;
		unsigned int row;

};

