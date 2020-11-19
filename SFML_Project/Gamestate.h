#pragma once
#include "State.h"

class Gamestate :
	public State
{
public:

	Gamestate(sf::RenderWindow* window);
	virtual ~Gamestate();
	
	//Function
	void endstate();
	void updatekeybind(const float &deltatime);
	void update(const float &deltatime);
	void render(sf::RenderTarget* target = nullptr);
private:

};

