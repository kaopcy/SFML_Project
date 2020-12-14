#pragma once
#include "Defination.h"
class Shuriken
{
public:
	Shuriken(sf::Texture& texture, sf::Vector2f firstposition , sf::Vector2f(aimdirectionnorm));
	~Shuriken();

	void update(const float& deltatime, const sf::Vector2f& degree, const bool& sharingan, const bool &throwshuriken, const sf::Vector2f& playerposition);
	void draw(sf::RenderWindow& window);
	sf::FloatRect getshape() { return this->hitbox.getGlobalBounds(); }
	sf::Vector2f getcenter() { return sf::Vector2f(this->shape.getPosition().x + this->shape.getSize().x / 2, this->shape.getPosition().y + this->shape.getSize().y / 2); }

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
	bool stickPlayer = true;
	float lifetime = 10;

};

