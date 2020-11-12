#pragma once
#include <SFML/Graphics.hpp>
class Bullet
{
public:

	Bullet(sf::Vector2f size = sf::Vector2f(30.0f, 20.0f))
		:currentvelocity(0.0f, 0.0f), speed(50.0f)
	{
		this->tbullet.loadFromFile("pic/bullet.png");
		this->shape.setSize(size);
		this->shape.setScale(2.0,2.0);
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
	~Bullet();
	float reload = 1.0f;
	float speed;
	sf::RectangleShape shape;
	sf::Vector2f currentvelocity;
	sf::Texture tbullet;
	void update() {
		this->hitbox.setPosition(shape.getPosition());
		this->hitbox.setRotation(shape.getRotation());
	}
	void draw(sf::RenderWindow& window) { window.draw(shape); window.draw(hitbox); }
private:
	sf::RectangleShape hitbox;
};

