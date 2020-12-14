#pragma once
#include "State.h"
#include <stack>
class Mainmenustate :
    public State
{
public:
	Mainmenustate(sf::RenderWindow* window);
	virtual ~Mainmenustate();
	//Function
	void endstate();
	void updatekeybind(const float& deltatime , sf::Event &evnt);
	void Buttoncheck(const float& deltatime);

	void update(const float& deltatime ,sf::Event &evnt);
	void render(sf::RenderWindow& window);
	void bgmove(const float deltatime);
private:
	sf::Sprite Bg_walking;
	sf::RectangleShape Bg;
	Texteiei Text3;
	Texteiei Text2;
	Texteiei Text1;
	sf::Texture tbackground;
	sf::Texture tbackgroundwalking;
	 float textsize = 100;
	 float textsize2 = 100;
	float i = 0;
	float offsetspeed = 0;
	sf::View view;
};

