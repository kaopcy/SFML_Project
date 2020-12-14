#include "Shuriken.h"

Shuriken::Shuriken(sf::Texture &texture , sf::Vector2f firstposition, sf::Vector2f(aimdirectionnorm))
{
	this->direction = aimdirectionnorm;
	this->shape.setPosition(firstposition);
	this->shape.setTexture(&texture);
	this->shape.setSize(sf::Vector2f(texture.getSize().x, texture.getSize().y));
	

	this->hitbox.setPosition(this->shape.getPosition());
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineColor(sf::Color::Blue);
	this->hitbox.setOutlineThickness(1.0);

}

Shuriken::~Shuriken()
{
}

void Shuriken::update(const float& deltatime , const sf::Vector2f &degree , const bool &sharingan, const bool &throwshuriken , const sf::Vector2f& playerposition)
{
	if (throwshuriken and stickPlayer)
		this->shape.setPosition(playerposition);
	else
	{
		stickPlayer = false;
		this->shape.move(direction.x * speed * deltatime , direction.y *speed * deltatime);
	}
	this->shape.setScale(scale, scale);
	this->shape.setRotation(spin);
	this->shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
	this->hitbox.setOrigin(hitbox.getSize().x / 2, hitbox.getSize().y / 2);

	this->hitbox.setRotation(this->shape.getRotation());
	this->hitbox.setPosition(this->shape.getPosition());
	this->hitbox.setSize(this->shape.getSize());
	this->hitbox.setScale(this->shape.getScale());
	scale += (deltatime * 1);
	lifetime -= deltatime;

	if (sharingan)
	{
		spin += 2;
		scale += (deltatime*0.5);
		speed = 50;
		aftersharigan = false;
	}
	else if(!sharingan and !aftersharigan)
	{
		scale += (deltatime * 2);
		speed = 2000;
		aftersharigan = true;
	}
		spin += 15;
	speed += 4;

}

void Shuriken::draw(sf::RenderWindow& window)
{
	window.draw(this->shape);
	window.draw(this->hitbox);
}
