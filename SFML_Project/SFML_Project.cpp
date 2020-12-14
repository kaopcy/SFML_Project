#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <sstream>  
#include <string.h>
#include "Game.h"
using namespace std;
using namespace sf;
sf::Texture btexture;
sf::Texture groundTexture;
sf::Texture tHP;
sf::Texture tbullet;
sf::Texture tFireball;
sf::Texture FireBackground;
///<Game Value Declaration>///
int life = 500;
float sec = 0;
float degree;
///<START MAIN>///
int main()
{

	tHP.loadFromFile("hpbar/EnemyHpbar.png");
	btexture.loadFromFile("Background/cartoon_background.jpg");
	btexture.setSmooth(1);
	groundTexture.loadFromFile("Background/Ground.png");

	FireBackground.loadFromFile("Background/BackgroundFire.png");
	tFireball.loadFromFile("Flame/Fireball.png");
	tbullet.loadFromFile("Shuriken/Shuriken.png");

	groundTexture.setSmooth(1);
	Game game;
	game.core();
	return (0);
}











