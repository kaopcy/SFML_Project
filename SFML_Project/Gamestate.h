#pragma once
#include "State.h"
extern sf::Texture fuckyou;

class Gamestate :
	public State 
{
public:
	Gamestate(sf::RenderWindow* window);
	virtual ~Gamestate();
	Soundhead soundeffect;
	//Function
	void updatedt(const float& deltatime);
	void endstate();
	void updatekeybind(const float &deltatime, sf::Event &evnt);
	void update(const float &deltatime , sf::Event &evnt);
	void render(sf::RenderWindow& window);
	void Degreecalculate();
	void platformUpdate(const float& deltatime);
	void drawtext(sf::RenderWindow& window);
	void skill(const float &deltatime);
	void animationsharingan(const float& deltatime);
	void BossShoot();
	///<Float function>
	
//Void ultimate 
	void ultimatefunc(const float& deltatime);
	bool ultimate = false;

//functionforShuriken
	void KeybindShuriken();
	bool throwshuriken = false;
	void updateShuriken();

	float randowplatform(float, float);
private:
	///<Texture>

	///<Class>
	Player player1;
	Enemy enemy1;
	Texteiei Text1;
	Texteiei Text2;
	Texteiei Text3;
	Bullet bullet;
	Bullet bulletoni;
	Background_move background1;
	Boss oni;

	///<vector>
	std::vector<Enemy> enemies;
	std::vector<Bullet> bullets;
	std::vector<Bullet> oniBullets;

	std::vector<Platform> platforms;
	std::vector<Soundhead> deadeffects;
	std::vector<Shuriken> shurikenbigs;
	
	///<time control>
	float deltatime = 0;
	float offsetYplayer = 0;
	int life = 500;
	float sec = 0;
	int enemycount = 0;
	float degree;
	float teleporttimer = 0;
	float slashtimer = 0;
	sf::Vector2f mouseposiforteleport;
	sf::Vector2f playerpositionbeforeteleport;

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
	sf::Sprite splashitachi;
	sf::Sprite splashitachi1;

	sf::Texture plattexture;
	sf::Texture plattexture2;
	sf::Texture plattexture3;
	sf::Texture tbackground;
	sf::Texture Tsplashitachi;
	sf::Texture shuriken_big;

	float itachiscale = 1;
	float itachirotation = 0;
	float itachidx = 50;
	//Flag
	bool flag1 = false;
	bool onceSwitchWeapon = true;
	bool slow = false;
	bool teleport = false;
	bool setmouseposiforteleport = true;
	bool slash = false;
	short int sharinguneye = 0;
	float offsetsharingan = 0;
	float sharinganeyetime = 2;
	bool itachisharingan = false;


};

