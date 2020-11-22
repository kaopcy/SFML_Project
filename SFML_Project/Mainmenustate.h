#pragma once
#include "State.h"
class Mainmenustate :
    public State
{
public:
	Mainmenustate(sf::RenderWindow* window);
	virtual ~Mainmenustate();
	//Function
	void endstate();
	void updatekeybind(const float& deltatime , sf::Event evnt);
	void update(const float& deltatime ,sf::Event evnt);
	void Buttoncheck(const float& deltatime);

	void render(sf::RenderWindow& window);
private:
	sf::RectangleShape Bg;
	Texteiei Text3;
	Texteiei Text2;
	Texteiei Text1;
	sf::Texture tbackground;
	 float textsize = 100;
	 float textsize2 = 100;

};

