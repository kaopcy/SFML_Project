#pragma once
#include <sfml/Graphics.hpp>

class Platform
{
public:
	Platform(sf::Texture *texture , sf::Vector2f size, float speed, sf::Vector2f position);
	~Platform();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
	sf::RectangleShape hitbox;
private:
	sf::RectangleShape body;
};

