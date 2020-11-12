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
	~Texteiei();
	void text1(float number, sf::RenderWindow& window, sf::Vector2f position, string str);

private:
	sf::Text Text1;

	sf::Font font;
};
