#pragma once
#include<SFML/Graphics.hpp>
class Enemy
{
public:
	sf::RectangleShape hitbox;
	Enemy(sf::Texture* Texplode , sf::Texture *texture ,sf::Vector2u imageframe);
	~Enemy();
	void update(float deltatime);
	void draw(sf::RenderWindow& window);
	void drawexplode(sf::RenderWindow& window);

public:
	float dx = 1;
	float dy = 0;
	bool flag = false;
	bool dead = false;
	float lifetime = 0.8;
private:
	sf::Vector2u currentframeexplode;
	sf::Sprite explosion;
	sf::Sprite S_enemy;
	float deltatime = 0;
	sf::Vector2u currentframe;
	sf::Vector2u imageframe;
	int animationframe;
	int row = 0;
	float offsetanimation = 0;
	float offset2 = 0;
	float offsetenemyspeed = 0;
	float deltatime_enemy = 0;
	float animationexplode = 0;
};

