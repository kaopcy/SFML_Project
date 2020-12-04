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
///<Game Value Declaration>///
int life = 500;
float sec = 0;
float degree;
///<START MAIN>///
int main()
{
	btexture.loadFromFile("Background/New_background.jpg");
	btexture.setSmooth(1);
	groundTexture.loadFromFile("Background/Ground.png");
	groundTexture.setSmooth(1);
	Game game;
	game.core();
	return (0);
}











