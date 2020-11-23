#pragma once
#include <sfml/Graphics.hpp>

class Platform
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, float offset, int speed, sf::Vector2f position, bool directiton);
	virtual ~Platform();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
	void moving(float multiple, const float& deltatime);

	sf::RectangleShape hitbox;
	int animation = 0;
	float getbot() { return hitbox.getPosition().y + hitbox.getSize().y; }
	float getright() { return hitbox.getPosition().x + hitbox.getSize().x; }
	float lifetime = 5;
	void stop() { dx = 0; }
	int speed;
	float dx = 0;
	float  dy = 0;
	
private:
	sf::RectangleShape body;
	sf::Vector2f size;
	sf::Vector2f position;
};

