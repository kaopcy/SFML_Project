#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <sstream>  
#include <string.h>
#include "player.h"
#include "Background_move.h"
#include "Walkground.h"
#include "Text.h"
#include "Bullet.h"
#include "Platform.h"
#include "Enemy.h"

using namespace std;
using namespace sf;
class Game 
{
private:

	///<Texture>
	sf::Texture plattexture;
	sf::Texture plattexture2;
	sf::Texture plattexture3;
	sf::Texture tbackground;
	sf::Texture tcursor;

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

	//time control 
	float offsetYplayer = 0;

	float deltatime = 0;
	int life = 500;
	float sec = 0;
	float degree;
	int enemycount = 0;
	bool flag1 = false;

	//Normal declaration
	short int enemyspawntimer = 0;
	short int bulletspawntimer = 0;
	short int platformnum = 0;


private:
	//Important declaration
	sf::RenderWindow *window;
	sf::Event evnt;
	sf::Clock clock;
	sf::Vector2f playercenter;
	sf::Vector2f mouseposition;
	sf::Vector2f aimdirection;
	sf::Vector2f aimdirectionnorm;
	sf::Vector2f velocitybullet;
	sf::Sprite cursor;
public :
	//Constructor
	Game();
	~Game();

	//Void function
	void core();
	void updateDt();
	void updateEvent();
	void update();
	void render();
	void run();
	void Event();
	void loadbackground();
	void initWindow();
	void Degreecalculate();
	void platformUpdate();
	//Float function
	float randowplatform(float, float);
};

