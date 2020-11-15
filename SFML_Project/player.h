#pragma once
#include<SFML/Graphics.hpp>
#include "Enemy.h"
#include "Walkground.h"
#include "colider.h"
#include "collision_test.h"

using namespace sf;
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageframe, float speed);
	~Player();
	void update(float delta_player, float ground, float degree);
	void draw(sf::RenderWindow& window);
	void moveplayer();
	void setposi(sf::Vector2f position) { player.setPosition(position); }

	///<For return some value>
	sf::FloatRect getglobalbound() { return player.getGlobalBounds(); };
	sf::Vector2f getcenter() { return sf::Vector2f(player_clone.left + player_clone.width / 2, player_clone.top + player_clone.height / 2); }
	float getbot() { return player_clone.top + player_clone.height; }
	float getright() { return player_clone.left + player_clone.width; }
	float getleft() { return player_clone.left; }
	float gettop() { return player_clone.top; }

public:
	sf::RectangleShape hitbox;
	sf::FloatRect player_clone;
	sf::Sprite player;
	sf::Vector2f velocity;
	sf::Vector2u currentframe;
	sf::RectangleShape arm;

	bool onground = false;
	float testspeed = 15.0;
	float dx, dy;
	float add = 0;
	int row;
	bool playercollision = false;
	sf::Vector2f direction;
	bool faceright;
	bool openUp = true;

private:
	sf::Vector2u imageframe;
	sf::Vector2f frame;
	sf::FloatRect platform;
	sf::CircleShape circle;
	float degree;
	float switchtime = 0.15f;
	bool fly = false;
	float ground = 750;
	float delta_player;
	int gravity = 12;
	int animationframe;
	float offsetanimation = 0;
	float offsetadd = 0;
	float offsetadd2 = 0;
	bool jumpstate;
	bool freefall;
};