#pragma once
#include<SFML/Graphics.hpp>
class Background_move
{
public:
	Background_move(sf::Texture *texture);
	virtual ~Background_move();
	sf::Sprite backgroundmove;
	void draw(sf::RenderWindow& window, bool& sharingan);
	void background_update(float deltatime , bool &sharingan);
private:
	sf::Texture btexture;
	sf::Sprite stopbackgroundmove;

	int i=0;
	float totaltime=0;
};

