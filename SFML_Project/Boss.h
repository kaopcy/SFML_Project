#pragma once
#include "Defination.h"
class Boss
{
public:
	Boss();
	virtual ~Boss();
	void draw(sf::RenderWindow& window);
	void update(const float& deltatime , const float& ground, const sf::Vector2f &playerPosition);
	void bossjump(const float& deltatime, const float& ground);
	void degreecalculate(const sf::Vector2f& playerPosition);

	float getright() { return this->shape.getPosition().x + this->shape.getSize().x; }
	float getleft() { return this->shape.getPosition().x; }
	float getbot() { return this->shape.getPosition().y + this->shape.getSize().y; }
	float gettop() { return this->shape.getPosition().y; }
	sf::Vector2f aimDirect() { return sf::Vector2f(this->shape.getPosition().x + shape.getSize().x * (0.5) , this->shape.getPosition().y + ( shape.getSize().y * (float)(0.25) ));}

	int BulletSpawnTimer = 0;
	int BulletReload = 12;
	sf::Vector2f aimdirectionnorm;

private:
	sf::CircleShape circle;
	sf::RectangleShape shape;
	sf::RectangleShape hitbox;

	float deltaX = 0;
	float deltaY = 0;
	float timetojump = 0;
	bool onground = false;
	sf::Vector2f direct;

	sf::Vector2f mouseposition;
	sf::Vector2f aimdirection;
	sf::Vector2f velocitybullet;

	
};

