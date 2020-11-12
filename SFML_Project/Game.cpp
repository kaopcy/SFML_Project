#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Mark Lee Die D Die", sf::Style::Close | sf::Style::Fullscreen);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::updateDt()
{
		deltatime = clock.restart().asSeconds();
}

void Game::updateEvent()
{
	if (this->window->pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::Resized:
			std::cout << "New window width " << evnt.size.width << " New window height " << evnt.size.height << std::endl;
			break;
		case sf::Event::KeyReleased:
			if (sf::Keyboard::A || sf::Keyboard::D)
			{
			}
		}
		if (evnt.type == evnt.Closed)
		{
			window->close();
		}
	}
}
void Game::update()
{
	this->updateEvent();
}

void Game::render()
{
	window->clear();
	//Draw everything


	window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
