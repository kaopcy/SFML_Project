#include "Game.h"

Game::Game() 
{
	this->initWindow();
	this->initstate();
	this->loadbackground();
}

Game::~Game()
{
	delete this->window;
	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}

}

void Game::initWindow()
{
	srand(time(NULL));
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Mark Lee Die D Die", sf::Style::Close | sf::Style::Fullscreen);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);

}

void Game::initstate()
{
	this->states.push(new Mainmenustate(this->window));
}

void Game::loadbackground()
{
}

void Game::Event()
{
	if (window->pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		/*case sf::Event::KeyReleased:
		{
			switch (evnt.key.code) 
			{
			case sf::Keyboard::A:
				player1.row = 4;
				break;
			case sf::Keyboard::D:
				player1.row = 4;
			}
		}*/
			
		}
		if (evnt.type == evnt.Closed)
		{
			window->close();
		}
	}
}

void Game::updateDt()
{
	deltatime = clock.restart().asSeconds();
}

void Game::core()
{
	tcursor.loadFromFile("cursor.png");
	cursor.setTexture(tcursor);
	cursor.setScale(0.04, 0.04);
	cursor.setOrigin(tcursor.getSize().x / 2, tcursor.getSize().y / 2);
	//Platform
	this->windowopen();
}

void Game::windowopen()
{
	while (window->isOpen())
	{
		cursor.setPosition(sf::Vector2f(sf::Mouse::getPosition()));
		this->updateDt();
		this->Event();
		if (!this->states.empty())
		{
			this->states.top()->update(this->deltatime , evnt);
			if (this->states.top()->getaddstate())
			{
				this->states.push(new Gamestate(this->window));
				
			}

			if (this->states.top()->getquit())
			{
				this->states.top()->endstate() ;
				delete this->states.top();
				this->states.pop();
			}
		}

		else
		{
			this->window->close();
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{

			///...<UPDATE GAME VALUE>...


			///...<KEYBOARD BUFFER>...
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O)) { this->states.push(new Mainmenustate(this->window));}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I)) {  }

			///...<UPDATE>...
			/*this->update();*/

			///<START DRAWING>///
			this->render();

		}
	}
}


void Game::render()
{
	window->clear();
	if (!this->states.empty())
	{
		this->states.top()->render(*window);
	}
	window->draw(this->cursor);
	window->display();

}
