#include "Mainmenustate.h"
Mainmenustate::Mainmenustate(sf::RenderWindow* window   ):
	State(window)
{
	this->tbackgroundwalking.loadFromFile(Background_File_Path);
	this->Bg_walking.setTexture(tbackgroundwalking);
	this->Bg_walking.setTextureRect(sf::IntRect(0, 0,1920, 1080));

	this->tbackground.loadFromFile("background/background_mainmenu_stoping.png");
	this->Bg.setTexture(&tbackground);
	this->Bg.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->Bg.setPosition(0, 0);
	view.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	view.setCenter(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));

}

Mainmenustate::~Mainmenustate()
{

}

void Mainmenustate::endstate()
{

}

void Mainmenustate::updatekeybind(const float& deltatime , sf::Event &evnt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window->close();
	}
}

void Mainmenustate::update(const float& deltatime , sf::Event &evnt)
{
	this->updatekeybind(deltatime, evnt);
	this->Buttoncheck(deltatime);
	this->checkforquit();
	this->bgmove(deltatime);

}

void Mainmenustate::render(sf::RenderWindow& window)
{
	window.setView(view);
	window.draw(Bg_walking);
	window.draw(Bg);
	Text2.Jumpingtext(window, (string)"Start", textsize, sf::Vector2f(100.0f, 0.0f), sf::Vector3i(253, 227, 155), 580, (float) 8 , 1);
	Text1.Jumpingtext(window, (string)"Exit", textsize2, sf::Vector2f(2000.0f, 0.0f), sf::Vector3i(253, 227, 155), 780, (float)9.40, 0);
}


void Mainmenustate::Buttoncheck(const float& deltatime)
{
	if (Text2.hitboxGBB().contains(sf::Mouse::getPosition()))
	{
		textsize = 150;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			cout << "HolyShit";
			addstate = true;
		}
	}
	else textsize = 100;
	if (Text1.hitboxGBB().contains(sf::Mouse::getPosition()))
	{
		textsize2 = 150;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			window->close();
		}
	}
	else textsize2 = 100;

}


void Mainmenustate::bgmove(const float deltatime)
{
	i++;
	this->Bg_walking.setTextureRect(sf::IntRect(i, 0, 1920, 1080));
	if (i >= 7680)
	{
		i = 0;
	}
}
