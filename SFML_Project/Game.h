#pragma once
#include "Gamestate.h"
#include "Mainmenustate.h"
using namespace std;
using namespace sf;
class Game 
{
private:
	sf::Texture tcursor;
	float deltatime = 0;

private:
	///<Important declaration>
	sf::RenderWindow *window;
	sf::Event evnt;
	sf::Clock clock;
	sf::Sprite cursor;
	sf::View view;
	std::stack<State*> states;

public :
	///<constructor>
	Game();
	virtual ~Game();

	///<Void function>
	void core();
	void updateDt();
	void windowopen();
	void render();
	void Event();
	void loadbackground();
	void initWindow();
	void initstate();
	
};

