#pragma once
#include<SFML/Graphics.hpp>
#include "Defination.h"
class Enemy
{
public:
	sf::RectangleShape hitbox;
	Enemy(int texturenum ,int hp ,sf::Vector2u imageframe);
	virtual ~Enemy();
	void update(float deltatime , bool &slash);
	void draw(sf::RenderWindow& window);
	void drawexplode(sf::RenderWindow& window);
	float calculateHP(int hp, float sizeX);
	void texturecontrol(int);
	void playDeadSound(bool dead);


//Editable vaule
public:
	int hp;
	float lifetime = 1.5;

public:
	bool flag = false;
	bool dead = false;
	
	float dy = 4;
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
	int row_explode = 0;

	bool deadflag = true;
	sf::SoundBuffer Deadsoundbuffer;
	sf::Sound Deadeffect;
};

