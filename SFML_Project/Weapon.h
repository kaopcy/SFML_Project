#pragma once
#include<SFML/Graphics.hpp>
class Weapon
{
public:
	Weapon();
	~Weapon();

public:
	unsigned short int weaponnum = 0;

private:

	sf::Texture Tbullet;
	sf::Texture Tflame;
	sf::RectangleShape bullet;
	sf::RectangleShape flame;

};

