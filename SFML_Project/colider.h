#pragma once
#include<SFML/Graphics.hpp>
#include"player.h"
#include "Walkground.h"
class colider
{
public:
	colider(sf::RectangleShape body); // รับค่า body ของอะไรก็ได้เข้ามา 1 ตัว 
	~colider();
	bool checkcolider(colider other, colider push); //ความเร็วถ้าของที่ผลักหนัก
	sf::Vector2f getposition() { return body.getPosition(); };
	sf::Vector2f gethalfsize() { return body.getSize() / 2.0f; };
private:
	sf::RectangleShape& body; //this body is for object body
};

