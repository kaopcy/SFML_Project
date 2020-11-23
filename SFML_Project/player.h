#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
class Player
{
public:
	Player(int playertex , sf::Vector2u imageframe, float speed);
	virtual ~Player();
	void update(float delta_player , const float degree);
	void draw(sf::RenderWindow& window);
	void moveplayer();
	void setposi(sf::Vector2f position) { player.setPosition(position); }
	void texturecontrol(int);

	///<For return some value>
	sf::FloatRect getglobalbound() { return player.getGlobalBounds(); };
	sf::Vector2f getcenter() { return sf::Vector2f(player_clone.left + player_clone.width / 2, player_clone.top + player_clone.height / 2); }
	float getbot() { return player_clone.top + player_clone.height; }
	float getright() { return player_clone.left + player_clone.width; }
	float getleft() { return player_clone.left; }
	float gettop() { return player_clone.top; }

public:
	sf::RectangleShape hptexture;
	sf::RectangleShape hitbox;
	sf::FloatRect player_clone;
	sf::Sprite player;
	sf::Vector2f velocity;
	sf::Vector2u currentframe;
	sf::RectangleShape arm;

	short int weaponInput = 0;
	short int getWeapon() { return weaponInput % 2; }

	void armDisable( short int, const float degree);
	bool onground = false;
	float testspeed = 15.0;
	float dx, dy;
	float speed = 1000;
	float add = 0;
	int row = 0;
	bool playercollision = false;
	sf::Vector2f direction;
	unsigned int hp = 10;
	bool sharingan = false;
	float sharingantimer = 5;

private:
	sf::Texture tplayer;
	sf::Texture thp;
	sf::RectangleShape hpbar;
	sf::Vector2u imageframe;
	sf::Vector2f frame;
	sf::FloatRect platform;
	sf::CircleShape circle;
	float switchtime = 0.15f;
	bool fly = false;
	float delta_player = 0;
	int gravity = 12;
	int animationframe = 0;
	float offsetanimation = 0;
	float offsetadd = 0;
	float offsetadd2 = 0;

};

