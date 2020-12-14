#pragma once
#include<SFML/Graphics.hpp>
#include "Defination.h"
class Enemy
{
public:
	sf::RectangleShape hitbox;
	Enemy(sf::Texture& texture2, sf::Texture &texture ,int texturenum ,int hp ,sf::Vector2u imageframe , const sf::Vector2f &firstPosition);
	virtual ~Enemy();
	void update(float deltatime , bool &slash , const float &ground);
	void draw(sf::RenderWindow& window);
	void drawexplode(sf::RenderWindow& window);
	float calculateHP(int hp, float sizeX);
	void texturecontrol(int);
	void playDeadSound(bool dead);

	sf::Vector2f getCenter() { return sf::Vector2f(this->hitbox.getPosition().x + hitbox.getSize().x / 2, this->hitbox.getPosition().y + hitbox.getSize().y / 2); }
	float getbot() { return getCenter().y + hitbox.getSize().y/2; }
	float gettop() { return getCenter().y - hitbox.getSize().y / 2; }
	float getleft() { return getCenter().x - hitbox.getSize().x / 2; }
	float getright() { return getCenter().x + hitbox.getSize().x / 2; }




//Editable vaule
public:
	int hp;
	float lifetime = 1.5;

public:
	bool changePhases = false;
	bool flag = false;
	bool dead = false;
	bool erase = false;
	float dy = 4;
	float dx = 1;
private:
	//For declare texture 


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

