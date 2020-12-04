#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, float offset, int speed, sf::Vector2f position , bool directiton)
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

	if (directiton) { this->dx = 1; }
	if (!directiton) { this->dx = -1; }
}

Platform::~Platform()
{
}

void Platform::Update(float deltatime)
{
	body.setTextureRect(sf::IntRect(size.x * animation, 0, size.x, size.y));
	
	
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



}



void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(hitbox);
}

void Platform::moving(float multiple, const float& deltatime)
{
	
	body.setPosition(sf::Vector2f(hitbox.getPosition().x, hitbox.getPosition().y + hitbox.getSize().y));
	hitbox.move(speed * 0 * deltatime * multiple, dy * 200 * deltatime);
}
