#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class Game 
{
private:
	void initWindow();
	sf::RenderWindow *window;
	sf::Event evnt;
	sf::Clock clock;
	float deltatime = 0;

public :
	Game();
	~Game();

	//function
	void updateDt();
	void updateEvent();
	void update();
	void render();
	void run();

};

