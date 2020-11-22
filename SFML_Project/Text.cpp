#include "Text.h"
#include<iostream>
#include <sstream>  
#include <string.h>
#include "Player.h"
using namespace std;
Texteiei::Texteiei()
{
	font.loadFromFile("Font/Font_cartoon.otf");
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(1);
	hitbox.setOutlineColor(Color::Red);
}
Texteiei::~Texteiei() {}
void Texteiei::numberwithtext(sf::RenderWindow& window, float number, string str, float size, sf::Vector2f position, sf::Vector3i colour)
{
	stringstream num;
	num << str << number;
	Text1.Bold;
	Text1.setFont(font);
	Text1.setPosition(position.x, position.y);
	Text1.setCharacterSize(size);
	Text1.setString(num.str());
	Text1.setFillColor(sf::Color(colour.x, colour.y, colour.z));
	window.draw(Text1);
}

void Texteiei::textOnly(sf::RenderWindow& window, string str, float size, sf::Vector2f position, sf::Vector3i colour)
{
	Text1.Bold;
	Text1.setFont(font);
	Text1.setPosition(position.x, position.y);
	Text1.setCharacterSize(size);
	Text1.setString(str);
	Text1.setFillColor(sf::Color(colour.x, colour.y, colour.z));
	window.draw(Text1);
}

void Texteiei::Movingtext(sf::RenderWindow& window, string str, float size, sf::Vector2f position, sf::Vector3i colour, sf::Vector2f direct)
{
	if (flagSetposition)
	{
		Text1.setPosition(position.x, position.y);
		flagSetposition = false;
	}

	Text1.Bold;
	Text1.setFont(font);
	Text1.setCharacterSize(size);
	Text1.setString(str);
	Text1.setFillColor(sf::Color(colour.x, colour.y, colour.z));

	Text1.move(direct.x, direct.y);

	window.draw(Text1);

}

void Texteiei::Jumpingtext(sf::RenderWindow& window, string str, float size, sf::Vector2f position, sf::Vector3i colour, float jumpandborder, float directx, bool right)
{

	if (flagSetposition)
	{
		Text1.setPosition(position.x, position.y);
		flagSetposition = false;
		if (right) directX = directx;
		if (!right) directX = -directx;
	}

	Text1.Bold;
	Text1.setFont(font);
	Text1.setCharacterSize(size);
	Text1.setString(str);
	Text1.setFillColor(sf::Color(colour.x, colour.y, colour.z));
	Text1.setOrigin(Text1.getGlobalBounds().width / 2, Text1.getGlobalBounds().height / 2);
	hitbox.setOrigin(hitbox.getSize().x / 2, hitbox.getSize().y / 2);

	if (right)
	{
		directY++;
		directX -= 0.04;
		if (directX <= 0)
		{
			directX = 0;
			stop = true;
		}
		if (Text1.getPosition().y >= jumpandborder)
		{
			if (!stop)
				directY = -20 + (directX - 0.02);
			if (stop)
				directY = 0;
		}

	}
	else
	{
		directY++;
		directX += 0.04;
		if (directX >= 0)
		{
			directX = 0;
			stop = true;
		}
		if (Text1.getPosition().y >= jumpandborder)
		{
			if (!stop)
				directY = -20 + (directX - 0.02);
			if (stop)
				directY = 0;
		}

	}
	Text1.move(directX, directY);
	hitbox.setSize(sf::Vector2f(Text1.getGlobalBounds().width, Text1.getGlobalBounds().height + 20));
	hitbox.setPosition(sf::Vector2f(Text1.getPosition().x, Text1.getPosition().y));

	window.draw(Text1);
}














