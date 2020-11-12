#pragma once
#include<SFML/Graphics.hpp>
class Background_move
{
public:
	Background_move(sf::Texture *texture);
	~Background_move();
	sf::Sprite backgroundmove;
	void draw(sf::RenderWindow& window);
	void background_update(float deltatime);
private:
	sf::Texture btexture;
	int i=0;
	float totaltime=0;
};

