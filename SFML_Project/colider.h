#pragma once
#include<SFML/Graphics.hpp>
#include"player.h"
#include "Walkground.h"
class colider
{
public:
	colider(sf::RectangleShape body); // �Ѻ��� body �ͧ���á�������� 1 ��� 
	~colider();
	bool checkcolider(colider other, colider push); //�������Ƕ�Ңͧ����ѡ˹ѡ
	sf::Vector2f getposition() { return body.getPosition(); };
	sf::Vector2f gethalfsize() { return body.getSize() / 2.0f; };
private:
	sf::RectangleShape& body; //this body is for object body
};

