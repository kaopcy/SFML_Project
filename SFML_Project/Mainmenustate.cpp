#include "Mainmenustate.h"
Mainmenustate::Mainmenustate(sf::RenderWindow* window):
	State(window)
{
	this->tbackground.loadFromFile("background/background_mainmenu.png");
	this->Bg.setTexture(&tbackground);
	this->Bg.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->Bg.setPosition(0, 0);
}

Mainmenustate::~Mainmenustate()
{

}

void Mainmenustate::endstate()
{

}

void Mainmenustate::updatekeybind(const float& deltatime , sf::Event evnt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window->close();
	}
}

void Mainmenustate::update(const float& deltatime , sf::Event evnt)
{
	this->updatekeybind(deltatime, evnt);
	this->Buttoncheck(deltatime);
	this->checkforquit();
}

void Mainmenustate::render(sf::RenderWindow& window)
{
	window.draw(Bg);
	Text2.Jumpingtext(window, (string)"Start", 100.0f, sf::Vector2f(100.0f, 0.0f), sf::Vector3i(253, 227, 155), 580, (float) 8 , 1);
	Text1.Jumpingtext(window, (string)"Exit", 100.0f, sf::Vector2f(2000.0f, 0.0f), sf::Vector3i(253, 227, 155), 780, (float)9.25, 0);
}

void Mainmenustate::Buttoncheck(const float& deltatime)
{
	if (sf::Mouse::getPosition().x >= Text2.getleft() and sf::Mouse::getPosition().x <= Text2.getright() and sf::Mouse::getPosition().y >= Text2.gettop() and sf::Mouse::getPosition().y <= Text2.getbot())
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			cout << "HolyShit";
			addstate = true;
		}
	}
	if (sf::Mouse::getPosition().x >= Text1.getleft() and sf::Mouse::getPosition().x <= Text1.getright() and sf::Mouse::getPosition().y >= Text1.gettop() and sf::Mouse::getPosition().y <= Text1.getbot())
	{
		window->close();
	}
}


