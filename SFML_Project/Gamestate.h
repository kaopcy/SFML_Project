#pragma once
#include "State.h"

class Gamestate :
	public State
{
public:
	Gamestate(sf::RenderWindow* window);
	virtual ~Gamestate();
	
	//Function
	void updatedt(const float& deltatime);
	void endstate();
	void updatekeybind(const float &deltatime, sf::Event evnt);
	void update(const float &deltatime , sf::Event evnt);
	void render(sf::RenderWindow& window);
	void Degreecalculate();
	void platformUpdate(const float& deltatime);
	void drawtext(sf::RenderWindow& window);
	///<Float function>
	float randowplatform(float, float);
private:
	///<Texture>
	sf::Texture plattexture;
	sf::Texture plattexture2;
	sf::Texture plattexture3;
	sf::Texture tbackground;

	///<Class>
	Player player1;
	Enemy enemy1;
	Texteiei Text1;
	Texteiei Text2;
	Texteiei Text3;
	Bullet bullet;
	Background_move background1;

	///<vector>
	std::vector<Enemy> enemies;
	std::vector<Bullet> bullets;
	std::vector<Platform> platforms;
	
	///<time control>
	float deltatime = 0;
	float offsetYplayer = 0;
	int life = 500;
	float sec = 0;
	int enemycount = 0;
	float degree;

	///<Normal declaration>
	short int enemyspawntimer = 0;
	short int bulletspawntimer = 0;
	short int platformnum = 0;

	///<Important declaration>
	sf::Vector2f playercenter;
	sf::Vector2f mouseposition;
	sf::Vector2f aimdirection;
	sf::Vector2f aimdirectionnorm;
	sf::Vector2f velocitybullet;
	sf::Sprite cursor;

	//Flag
	bool flag1 = false;
	bool onceSwitchWeapon = true;
};

