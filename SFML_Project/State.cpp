#include "State.h"

State::State(sf::RenderWindow* window)
{
	this->window = window; 
}

State::~State()
{
}

void State::checkforquit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))
	{
		this->quit = true;
	}
}

const bool& State::isEnd() const
{
	return this->gameOver;
}


const bool& State::getquit() const
{
	return this->quit;
}

const bool& State::getaddstate() const
{
	return this->addstate;
}
