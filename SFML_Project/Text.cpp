#include "Text.h"
#include<iostream>
#include <sstream>  
#include <string.h>
#include "Player.h"
using namespace std;
Texteiei::Texteiei()
{
	font.loadFromFile("font.ttf");
}
Texteiei::~Texteiei(){}
void Texteiei::text1(float number , sf::RenderWindow &window , sf::Vector2f position ,string str)
{
    stringstream num;
    num << str << number;
	Text1.Bold;
	Text1.setFont(font);
    Text1.setPosition(position.x, position.y);
    Text1.setCharacterSize(100);
    Text1.setString(num.str());
    window.draw(Text1);
}













