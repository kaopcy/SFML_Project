#pragma once
#include<SFML/Graphics.hpp>
class Background
{
public:
	Background();
	~Background();
	sf::Sprite backgroundmove;
	void draw(sf::RenderWindow & window);
private:
	sf::Texture btexture;

};

