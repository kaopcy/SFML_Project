#pragma once
#include <sfml/Graphics.hpp>

class Platform
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, float offset, int speed, sf::Vector2f position);
	~Platform();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
	sf::RectangleShape hitbox;
	int animation = 0;
	float getbot() { return hitbox.getPosition().y + hitbox.getSize().y; }
	float getright() { return hitbox.getPosition().x + hitbox.getSize().x; }
	float lifetime = 5;
	void stop() { dx = 0; }
	int speed;
private:
	sf::RectangleShape body;
	int dx = 1;
	int dy = 0;
	sf::Vector2f size;
	sf::Vector2f position;
};

