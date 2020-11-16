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
	

	///<Class>
	Player player1;
	Enemy enemy1;
	Texteiei Text1;
	Texteiei Text2;
	Texteiei Text3;

	void initWindow();
	sf::RenderWindow *window;
	sf::Event evnt;
	sf::Clock clock;
	float deltatime = 0;
	int life = 500;
	float sec = 0;
	float degree;
private:
	sf::Vector2f playercenter;
	sf::Vector2f mouseposition;
	sf::Vector2f aimdirection;
	sf::Vector2f aimdirectionnorm;
	sf::Vector2f velocitybullet;
public :
	Game();
	~Game();
	float randowplatform(float, float);
	//function
	void core();

	void updateDt();
	void updateEvent();
	void update();
	void render();
	void run();
};

