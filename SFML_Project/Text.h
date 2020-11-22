#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include <sstream>  
#include <string.h>
using namespace std;
class Texteiei
{
public:
	Texteiei();
	virtual ~Texteiei();
	void numberwithtext(sf::RenderWindow& window, float number, string str, float size,  sf::Vector2f position, sf::Vector3i colour);
	void textOnly(sf::RenderWindow& window, string str, float size, sf::Vector2f position, sf::Vector3i colour);
	void Movingtext(sf::RenderWindow& window, string str, float size, sf::Vector2f position, sf::Vector3i colour , sf::Vector2f direct);
	void Jumpingtext(sf::RenderWindow& window, string str, float size, sf::Vector2f position, sf::Vector3i colour, float jumpandborder, float directx , bool right );
	sf::RectangleShape hitbox;
	float getright() { return hitbox.getPosition().x + hitbox.getSize().x; }
	float getleft() { return hitbox.getPosition().x; }
	float gettop() { return hitbox.getPosition().y; }
	float getbot() { return hitbox.getPosition().y + hitbox.getSize().y; }





private:
	sf::Text Text1;
	bool flagSetposition = true;
	bool stop = false;
	sf::Font font;
	float directY = 0;
	float directX = 0;
};
