#pragma once
#include<SFML/Graphics.hpp>
#include "player.h"
class Weapon
{
public:
	Weapon( uint8_t weaponnum);
	~Weapon();

public:
	unsigned short int weaponnumber = 0;
	void weaponnum();
	void update();

private:
	sf::Texture Tbullet;
	sf::Texture Tflame;
	sf::RectangleShape bullet;
	sf::RectangleShape flame;

};

