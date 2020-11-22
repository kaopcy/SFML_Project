#include "Weapon.h"

Weapon::Weapon( uint8_t weaponnum)
{
	this->Tflame.loadFromFile("Flame/Flame.png");
	this->flame.setTexture(&Tflame);
	this->flame.setSize(sf::Vector2f(Tflame.getSize()));
}

Weapon::~Weapon()
{
}

void Weapon::weaponnum()
{

}

void Weapon::update()
{
}
