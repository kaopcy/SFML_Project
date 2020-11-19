#pragma once
#include "Gamestate.h"

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

	///<time control>
	float deltatime = 0;
	float offsetYplayer = 0;
	int life = 500;
	float sec = 0;
	float degree;
	int enemycount = 0;
	bool flag1 = false;

	///<Normal declaration>
	short int enemyspawntimer = 0;
	short int bulletspawntimer = 0;
	short int platformnum = 0;


private:
	///<Important declaration>
	sf::RenderWindow *window;
	sf::Event evnt;
	sf::Clock clock;
	sf::Vector2f playercenter;
	sf::Vector2f mouseposition;
	sf::Vector2f aimdirection;
	sf::Vector2f aimdirectionnorm;
	sf::Vector2f velocitybullet;
	sf::Sprite cursor;
	sf::View view;
	std::stack<State*> states;

public :
	///<constructor>
	Game();
	virtual ~Game();

	///<Void function>
	void core();
	void updateDt();
	void windowopen();
	void update();
	void render();
	void Event();
	void loadbackground();
	void initWindow();
	void initstate();
	void Degreecalculate();
	void platformUpdate();

	///<Float function>
	float randowplatform(float, float);
};

