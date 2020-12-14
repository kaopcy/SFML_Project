#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
class Player
{
public:
	Player(int playertex , sf::Vector2u imageframe, float speed);
	virtual ~Player();
	void update(float delta_player , const float degree, bool& ultimate ,const sf::Vector2f& view);
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
	sf::RectangleShape hitboxShield;
	sf::RectangleShape enegy;

	sf::FloatRect player_clone;
	sf::Sprite player;
	sf::Vector2f velocity;
	sf::Vector2u currentframe;
	sf::RectangleShape arm;

	short int weaponInput = 0;
	short int getWeapon() { return weaponInput % 2; }
	bool onplatform = false;
	int animationframe = 0;
	int animationframe1 = 0;

	void armDisable( short int, const float degree);
	bool onground = false;
	float testspeed = 15.0;
	float dx, dy;
	float speed = 0;
	float add = 0;
	int row = 0;
	bool playercollision = false;
	sf::Vector2f direction;
	unsigned int hp = 50;
	bool sharingan = false;
	float sharingantimer = 5;
	bool isShield = false;
	bool faceRight = true;
	bool resetanimation[10];

	float enegyFlow = 100;
	float hpFlow = 100;

private:
	//Hp && Mana
	float enegyMax = 100;
	float enegyRatio = 0;
	float hpMax = 100;
	float hpRatio = 1;
	sf::Texture tEnegy;
	sf::Sprite sEnegy;
	sf::Texture tHP;
	sf::Sprite sHP;
	sf::RectangleShape HP;
	sf::Vector2f hpBarSize;

	sf::Texture tplayer;
	sf::Texture tShield;
	sf::Sprite sShield;
	sf::Sprite flame;

	sf::Texture thp;
	sf::RectangleShape hpbar;
	sf::Vector2u imageframe;
	sf::Vector2f frame;
	sf::CircleShape circle;
	float switchtime = 0.15f;
	bool fly = false;
	float delta_player = 0;
	int gravity = 12;
	float offsetanimation = 0;
	float offsetadd = 0;
	float offsetadd2 = 0;
	sf::Vector2f enegybarSize;

};

