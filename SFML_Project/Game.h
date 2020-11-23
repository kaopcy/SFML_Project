#pragma once
#include "Gamestate.h"
#include "Mainmenustate.h"
#include "Assetmanager.h"
using namespace std;
using namespace sf;

struct Gamedata
{
	Assetmanager asset;
};

class Game :
	public Assetmanager
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
	Gamedata _data;
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
	void initWindow();
	void initstate();
	
};

