#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, float offset, int speed, sf::Vector2f position)
{
	this->speed = speed;
	this->position = position;

	body.setTexture(texture);
	body.setSize(size);
	body.setOrigin(0, body.getSize().y);
	hitbox.setPosition(position.x , 1500);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(1);
	hitbox.setOutlineColor(sf::Color::Green);
	hitbox.setSize(sf::Vector2f(size.x, (size.y / 2) + offset));
	this->size = size;
}

Platform::~Platform()
{
}

void Platform::Update(float deltatime)
{
	body.setTextureRect(sf::IntRect(size.x * animation, 0, size.x, size.y));
	body.setPosition(sf::Vector2f(hitbox.getPosition().x, hitbox.getPosition().y + hitbox.getSize().y));
	if (hitbox.getPosition().x > 1500 and dx == 1)
	{
		dx = -1;
	}
	if (hitbox.getPosition().x < 0 and dx == -1)
	{
		dx = 1;
	}
	lifetime -= deltatime;
	
	{

		if (hitbox.getPosition().y > position.y)
		{
			dy = -9;
		}
		else if (hitbox.getPosition().y < position.y or lifetime >= 2)
		{
			dy = 0;
		}

	}
	if (lifetime <= 0.4)
	{
		dy = 3;
	}

	hitbox.move(speed * dx * deltatime, dy * 200 * deltatime);


}

void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(hitbox);
}
