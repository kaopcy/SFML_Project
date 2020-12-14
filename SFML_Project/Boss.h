#pragma once
#include "Defination.h"
extern sf::Texture tHP;

class Boss
{
public:
	Boss(sf::Vector2f firstPos);
	virtual ~Boss();
	void draw(sf::RenderWindow& window);
	void update(const float& deltatime , const float& ground, const sf::Vector2f &playerPosition);
	void bossjump(const float& deltatime, const float& ground);
	void degreecalculate(const sf::Vector2f& playerPosition);
	void bossSkill();
	void HPManagement();
	void knockbackSkill (const sf::Vector2f& playerPosition, const float& deltatime);

	float getright() { return this->shape.getPosition().x + this->shape.getSize().x; }
	float getleft() { return this->shape.getPosition().x; }
	float getbot() { return this->shape.getPosition().y + this->shape.getSize().y; }
	float gettop() { return this->shape.getPosition().y; }
	sf::Vector2f getCenter() { return sf::Vector2f(this->shape.getPosition().x + (this->shape.getSize().x / 2), this->shape.getPosition().y + (this->shape.getSize().y / 2)); }
	sf::Vector2f aimDirect() { return sf::Vector2f(this->shape.getPosition().x + shape.getSize().x * (0.5) , this->shape.getPosition().y + ( shape.getSize().y * (float)(0.25) ));}

	int BulletSpawnTimer = 0;
	int BulletReload = 1;
	float bulletSpeed = 50;
	sf::Vector2f aimdirectionnorm;
	sf::RectangleShape hitbox;
	short int Movespeed = 100;
	float hpFlow = 100;

	bool healSkill = false;
	bool rapidSkill = false;
	bool knockback = false;
	bool setMovespeedKnockback = false;
private:
	sf::CircleShape circle;
	sf::RectangleShape shape;
	sf::RectangleShape HP;
	sf::Sprite sHP;

	float degree = 0;
	float deltaX = 0;
	float deltaY = 0;
	float BossTimer = 0;
	float HPratio = 1;
	float hpMax = 100;
	float knockbackTimer = 1;
	bool onground = false;
	sf::Vector2f direct;

	sf::Vector2f mouseposition;
	sf::Vector2f aimdirection;
	sf::Vector2f velocitybullet;
	sf::Vector2f HPbarSize;

	
};

