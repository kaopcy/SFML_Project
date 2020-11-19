#include "Gamestate.h"
Gamestate::Gamestate(sf::RenderWindow* window):
	State(window)
{

}


Gamestate::~Gamestate()
{
}

void Gamestate::endstate()
{
	cout << "end state " << endl;
}

void Gamestate::updatekeybind(const float &deltatime)
{
	this->checkforquit();

}


void Gamestate::update(const float &deltatime)
{
	this->updatekeybind(deltatime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		cout << "A" << endl;
	}
}

void Gamestate::render(sf::RenderTarget* target)
{
}
