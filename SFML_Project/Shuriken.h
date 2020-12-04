#pragma once
#include "Defination.h"
class Shuriken
{
public:
	Shuriken(sf::Texture& texture, sf::Vector2f firstposition , sf::Vector2f(aimdirectionnorm));
	~Shuriken();

	void update(const float& deltatime, const sf::Vector2f& degree, const bool& sharingan);
	void draw(sf::RenderWindow& window);
	sf::FloatRect getshape() { return this->hitbox.getGlobalBounds(); }
	
private:
	sf::RectangleShape shape;
	sf::RectangleShape hitbox;
	sf::Vector2f direction;
	float dx = 0;
	float dy = 0;
	float scale = 1;
	float spin = 0;
	float speed = 900;
	bool aftersharigan = false;

};

