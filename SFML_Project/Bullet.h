#pragma once
#include <SFML/Graphics.hpp>
class Bullet
{
public:

	Bullet(sf::Vector2f size = sf::Vector2f(30.0f, 20.0f))
		:currentvelocity(0.0f, 0.0f)
	{
		this->tbullet.loadFromFile("Shuriken/Shuriken.png");
		this->shape.setSize(sf::Vector2f(tbullet.getSize().x,tbullet.getSize().y ));
		this->shape.setScale(0.7,0.7);
		this->shape.setTexture(&tbullet);
		//this->shape.setFillColor(sf::Color::Magenta);
		this->shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
		this->hitbox.setSize(shape.getSize());
		this->hitbox.setPosition(shape.getPosition());
		this->hitbox.setOutlineThickness(1);
		this->hitbox.setOutlineColor(sf::Color::Green);
		this->hitbox.setFillColor(sf::Color::Transparent);
		this->hitbox.setOrigin(shape.getOrigin());
		
	}
	virtual ~Bullet();
	float reload = 5.0f;
	float speed = 25.0f;
	sf::RectangleShape shape;
	sf::Vector2f currentvelocity;
	sf::Texture tbullet;
	void update( const float &deltatime , bool &sharingan) {
		if (sharingan)
			spinspeed += 3;
		else
			spinspeed = 10;
		if (spinspeed >= 360)
			spinspeed = 0;
		this->shape.setRotation(spinspeed);
		this->hitbox.setScale(this->shape.getScale());
		this->hitbox.setPosition(shape.getPosition());
		this->hitbox.setRotation(shape.getRotation());
	}
	void draw(sf::RenderWindow& window) { window.draw(shape); window.draw(hitbox); }
private:
	sf::RectangleShape hitbox;
	float spinspeed = 0;
};

