#pragma once
#include<SFML/Graphics.hpp>
#include "colider.h"
#include "player.h"
using namespace sf;
class Walkground
{
public:
	sf::Vector2f movement;
	sf::RectangleShape body;
	FloatRect body_clone;
	Walkground(float speed, sf::Vector2f size, sf::Vector2f position);
	void update(float delta, float* ground );
	float gethalfX() { return body.getSize().x / 2.0f; }
	float gethalfY() { return body.getSize().y / 2.0f; }
	float getright() { return body.getPosition().x + gethalfX(); }
	float getleft()  { return body.getPosition().x - gethalfX(); }
	float gettop()	 { return body.getPosition().y - gethalfY(); }
	float getbot()   { return body.getPosition().y + gethalfY(); }
	void  draw(sf::RenderWindow& window) { window.draw(body); }
	float getposiX() { return body.getPosition().x ; }
	float getposiY() { return body.getPosition().y ; }
	void setposi(sf::Vector2f position) { body.setPosition(position); }
	sf::FloatRect getglobalbound() { return body.getGlobalBounds(); };




private:
	float dx = 1;
	float delta;
	float totaltime=0;
	float ground;
	float speed;
};

