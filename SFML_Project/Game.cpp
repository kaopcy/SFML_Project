#include "Game.h"

Game::Game() :
	player1(1, sf::Vector2u(5, 5), 100.0f),
	enemy1(1, 10, sf::Vector2u(4, 2)),
	background1(&tbackground)
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
	this->states.push(new Gamestate(this->window));
}

void Game::loadbackground()
{
	tbackground.loadFromFile("Background/Background.png");
	tcursor.loadFromFile("cursor.png");
	plattexture3.loadFromFile("Platform/Platform3.png");
	plattexture2.loadFromFile("Platform/Platform1.png");
	plattexture.loadFromFile("Platform/Platform2_fix.png");

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
		case sf::Event::KeyReleased:
		{
			switch (evnt.key.code) 
			{
			case sf::Keyboard::A:
				player1.row = 4;
				break;
			case sf::Keyboard::D:
				player1.row = 4;
			}
		}
			
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
	sec += deltatime;
}

void Game::core()
{
	cursor.setTexture(tcursor);
	cursor.setScale(0.04, 0.04);
	cursor.setOrigin(tcursor.getSize().x / 2, tcursor.getSize().y / 2);
	//Platform
	platforms.push_back(Platform(&plattexture, sf::Vector2f(plattexture.getSize().x / 3, plattexture.getSize().y), 0, 300, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 1000.0f)));
	platforms.push_back(Platform(&plattexture2, sf::Vector2f(plattexture2.getSize().x / 3, plattexture2.getSize().y), 20, 200, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 800.0f)));
	this->windowopen();
}

void Game::windowopen()
{
	while (window->isOpen())
	{
		cursor.setPosition(sf::Vector2f(sf::Mouse::getPosition()));
		player1.onground = false;
		this->updateDt();
		this->Event();
		if (!this->states.empty())
		{
			this->states.top()->update(this->deltatime);

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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) { window->close(); }

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				player1.dx = -1;
				player1.row = 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{
				player1.dx = 1;
				player1.row = 0;
			}

			if (bulletspawntimer < bullet.reload) { bulletspawntimer++; }
			if (bulletspawntimer == bullet.reload and bullets.size() < 100)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				{
					player1.row = 2;
					bullet.shape.setPosition(player1.getcenter());
					bullet.currentvelocity = aimdirectionnorm * bullet.speed;
					bullets.push_back(Bullet(bullet));
					bulletspawntimer = 0;
				}
			}
			///...<UPDATE>...
			this->update();

			///<START DRAWING>///
			this->render();

		}
	}
}

void Game::update()
{
	view.zoom(10);

	this->background1.background_update(this->deltatime);
	player1.update(deltatime, degree);
	player1.moveplayer();
	this->platformUpdate();
	if (player1.getbot() > window->getSize().y)
	{
		player1.player_clone.top = window->getSize().y - player1.player_clone.height;
		player1.onground = true;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		if (player1.onground)
		{
			player1.onground = false;
			player1.dy = -30;
		}
	}
	//Update Bullet Direction
	this->Degreecalculate();

	//Enemy update
	if (enemyspawntimer < 10) { enemyspawntimer++; }

	if (enemyspawntimer == 10)
	{
		enemy1.hitbox.setPosition(sf::Vector2f(rand() % window->getSize().x, -(enemy1.hitbox.getSize().y)));
		enemies.push_back(Enemy(enemy1));
		enemyspawntimer = 0;
	}
	//Checkshot
	for (size_t i = 0; i < enemies.size(); i++)
	{

		for (size_t k = 0; k < bullets.size(); k++)
		{
			if (enemies[i].hitbox.getGlobalBounds().intersects(bullets[k].shape.getGlobalBounds()) and !enemies[i].dead)
			{
				enemies[i].hp--;
				if (enemies[i].hp <= 0)
				{

					enemies[i].dead = true;
					enemycount++;
				}
				bullets.erase(bullets.begin() + k);
			}
		}
		enemies[i].update(deltatime);
		if (enemies[i].lifetime <= 0 and enemies[i].dead)
		{
			enemies.erase(enemies.begin() + i);
		}
	}

	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].hitbox.getGlobalBounds().intersects(player1.getglobalbound()) and !enemies[i].dead)
		{
			player1.hp--;
			cout << "hit" << endl;
			enemies.erase(enemies.begin() + i);
			if (player1.hp <= 0)
			{
				player1.hp = 10;
			}
		}
	}
	//Enemies Out of Bound
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].hitbox.getPosition().x + enemies[i].hitbox.getSize().x / 2.0f > player1.getcenter().x and !enemies[i].flag)
		{
			enemies[i].dx = -1;
			enemies[i].flag = true;
		}
		if (enemies[i].hitbox.getPosition().x + enemies[i].hitbox.getSize().x / 2.0f < player1.getcenter().x and !enemies[i].flag)
		{
			enemies[i].dx = 1;
			enemies[i].flag = true;
		}

		if (enemies[i].hitbox.getPosition().y > 1000)
		{
			enemies.erase(enemies.begin() + i);
		}
	}
	//Update Bullet
	for (size_t k = 0; k < bullets.size(); k++)
	{
		bullets[k].update();
		bullets[k].shape.setRotation(degree);
		bullets[k].shape.move(bullets[k].currentvelocity);
		if (bullets[k].shape.getPosition().y < 0 or bullets[k].shape.getPosition().y > window->getSize().y or bullets[k].shape.getPosition().x < 0 or bullets[k].shape.getPosition().x > window->getSize().x)
		{
			bullets.erase(bullets.begin() + k);
		}
	}
}

void Game::platformUpdate()
{
	if ((int)sec == 1 and flag1 == 0)
	{
		platformnum++;
		flag1 = true;
	}
	if ((int)sec == 4 and flag1 == 1)
	{
		platforms.push_back(Platform(&plattexture2, sf::Vector2f(plattexture2.getSize().x / 3, plattexture2.getSize().y), 20, 200, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 800.0f)));
		platformnum++;
		flag1 = false;
	}
	for (size_t i = 0; i < platforms.size(); i++)
	{
		if (platforms[i].lifetime <= 2)
		{
			platforms[i].animation = 1;
			if (platforms[i].lifetime <= 0.2)
			{
				platforms[i].animation = 2;
			}
			if (platforms[i].speed > 0)
				platforms[i].speed -= (5);
		}
		if (platforms[i].lifetime <= 0)
		{
			platforms.erase(platforms.begin() + i);
			platformnum++;
			switch (platformnum % 3)
			{
			case 0:
				platforms.push_back(Platform(&plattexture, sf::Vector2f(plattexture.getSize().x / 3, plattexture.getSize().y), 0, 300, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 1000.0f)));
				break;
			case 1:
				platforms.push_back(Platform(&plattexture2, sf::Vector2f(plattexture2.getSize().x / 3, plattexture2.getSize().y), 20, 200, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 800.0f)));
				break;
			case 2:
				platforms.push_back(Platform(&plattexture3, sf::Vector2f(plattexture3.getSize().x / 3, plattexture3.getSize().y), 20, 500, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 700.0f)));
				break;
			}
			break;
		}
		platforms[i].Update(deltatime);

	}

	for (size_t i = 0; i < platforms.size(); i++)
	{
		if (player1.player_clone.intersects(platforms[i].hitbox.getGlobalBounds()))
		{
			///<Right>///
			if (player1.getright() >= platforms[i].hitbox.getGlobalBounds().left
				and player1.getright() < platforms[i].hitbox.getGlobalBounds().left + 35
				) {
				player1.dx = 0.0f;
				player1.player_clone.left = platforms[i].hitbox.getGlobalBounds().left - player1.player_clone.width;
			}

			///<Left>///
			else if (player1.getleft() <= platforms[i].hitbox.getGlobalBounds().left + platforms[i].hitbox.getGlobalBounds().width
				and player1.getleft() > platforms[i].hitbox.getGlobalBounds().left + platforms[i].hitbox.getGlobalBounds().width - 35
				) {
				player1.dx = 0.0f;
				player1.player_clone.left = platforms[i].hitbox.getGlobalBounds().left + platforms[i].hitbox.getGlobalBounds().width;
			}

			///<Top>///
			else if (player1.player_clone.top + player1.player_clone.height > platforms[i].hitbox.getGlobalBounds().top
				and player1.getright() > platforms[i].hitbox.getGlobalBounds().left
				and player1.player_clone.left < platforms[i].hitbox.getGlobalBounds().left + platforms[i].hitbox.getGlobalBounds().width
				) {
				player1.player_clone.top = platforms[i].hitbox.getGlobalBounds().top - player1.player_clone.height;
				player1.onground = true;
				player1.dy = 0;

			}

		}



	}
}

void Game::Degreecalculate()
{
	degree = atan2(mouseposition.y - player1.getcenter().y, mouseposition.x - player1.getcenter().x) * (180 / 3.141);
	playercenter = sf::Vector2f(player1.player_clone.left + player1.currentframe.x / 2, player1.player_clone.top + player1.currentframe.y / 2);
	mouseposition = sf::Vector2f(sf::Mouse::getPosition(*window));
	aimdirection = mouseposition - playercenter;
	aimdirectionnorm = aimdirection / sqrt(pow(aimdirection.x, 2) + (pow(aimdirection.y, 2)));
	std::cout << aimdirectionnorm.x << "    " << -aimdirectionnorm.y << endl;
}

void Game::render()
{
	window->clear();
	if (!this->states.empty())
	{
		this->states.top()->render();
	}

	this->background1.draw(*window);
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].draw(*window);
		this->enemies[i].drawexplode(*window);
	}
	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i].draw(*window);
	}
	for (size_t i = 0; i < platforms.size(); i++) { platforms[i].Draw(*window); }
	player1.draw(*window);
	window->draw(this->cursor);
	/*Text1.text1(randowplatform(player1.getright(), rand() % 2), *window, sf::Vector2f(0.0f, 0.0f), (string)"Timerplatform 0: ");
	Text2.text1(player1.hp, *window, sf::Vector2f(0.0f, 150.0f), (string)"Timerplatform 1: ");*/
	Text3.text1((int)sec, *window, sf::Vector2f(1300.0f, 0.0f), (string)"Timer ");
	window->display();
}

float Game::randowplatform(float posiX, float sizeX)
{
	float size = posiX + sizeX;
	if (size <= window->getSize().x / 2)
	{
		return rand() % ((int)window->getSize().x - (int)sizeX) + sizeX;
	}
	else if (size >= window->getSize().x / 2)
	{
		return rand() % ((int)window->getSize().x - (int)sizeX) + sizeX;
	}

}
