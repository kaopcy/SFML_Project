#pragma once
#include<SFML/Graphics.hpp>
class Enemy
{
public:
	sf::Sprite S_enemy;
	Enemy(sf::Vector2u imageframe);
	~Enemy();
	void update(float deltatime, float *ground);
	void draw(sf::RenderWindow& window);
	void enemy_update(sf::RenderWindow& window);
public:
	sf::FloatRect enemy_collision;
	sf::Vector2f movement;
private:
	float deltatime = 0;
	float ground = 0;
	float maxX = 1900;
	sf::Texture P_enemy;
	sf::Vector2u currentframe;
	sf::Vector2u imageframe;
	int animationframe;
	int row;
	float offsetanimation = 0;
	float offsetenemyspeed = 0;
	float offsetadd2 = 0;
	float deltatime_enemy = 0;
};

