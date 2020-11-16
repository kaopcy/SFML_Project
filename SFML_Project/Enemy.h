#pragma once
#include<SFML/Graphics.hpp>
class Enemy
{
public:
	sf::RectangleShape hitbox;
	Enemy(int texturenum ,int hp ,sf::Vector2u imageframe);
	~Enemy();
	void update(float deltatime);
	void draw(sf::RenderWindow& window);
	void drawexplode(sf::RenderWindow& window);
	float calculateHP(int hp, float sizeX);
	void texturecontrol(int);
//Editable vaule
public:
	int hp;
	float lifetime = 0.8;

public:
	bool flag = false;
	bool dead = false;
	
	float dy = 0;
	float dx = 1;
private:
	//For declare texture 
	sf::Texture Etexture;
	sf::Texture Texplode;


	sf::RectangleShape hpRec;
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
	float minus = 0;
	float percent = 100;
	int hpmax;
};

