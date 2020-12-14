#include "Bullet.h"



Bullet::Bullet(sf::Texture& texture, float speed, const int type)
	:currentvelocity(0.0f, 0.0f),
	speed(speed),
	type(type)
{
	if (type == 1)
	{
		this->shape.setTexture(&texture);
		this->shape.setSize(sf::Vector2f(texture.getSize().x, texture.getSize().y));
		this->shape.setScale(0.7, 0.7);
		this->shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
		this->hitbox.setSize(shape.getSize());
		this->hitbox.setPosition(shape.getPosition());
		this->hitbox.setOutlineThickness(1);
		this->hitbox.setOutlineColor(sf::Color::Green);
		this->hitbox.setFillColor(sf::Color::Transparent);
		this->hitbox.setOrigin(shape.getOrigin());
	}
	else if (type == 2)
	{
		this->shape.setTexture(&texture);
		this->shape.setSize(sf::Vector2f(texture.getSize().x, texture.getSize().y));
		this->shape.setScale(0.1, 0.1);
		this->shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
		this->hitbox.setSize(shape.getSize());
		this->hitbox.setPosition(shape.getPosition());
		this->hitbox.setOutlineThickness(2);
		this->hitbox.setOutlineColor(sf::Color::Green);
		this->hitbox.setFillColor(sf::Color::Transparent);
		this->hitbox.setOrigin(shape.getOrigin());
	}
}

Bullet::~Bullet()
{
}

void Bullet::update(const float& deltatime, bool& sharingan)
{
	if (sharingan)
		spinspeed += 3;
	else
		spinspeed += 20;
	if (spinspeed >= 360)
		spinspeed = 0;
	this->shape.setRotation(spinspeed);
	this->hitbox.setScale(this->shape.getScale());
	this->hitbox.setPosition(shape.getPosition());
	this->hitbox.setRotation(shape.getRotation());

}

void Bullet::draw(sf::RenderWindow& window)
{
	window.draw(shape);
	window.draw(hitbox);
}
