#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <sstream>  
#include <string.h>
#include "player.h"
#include "Background_move.h"
#include "Walkground.h"
#include "Text.h"
#include "Bullet.h"
#include "Platform.h"
using namespace std;
using namespace sf;



///<Game Value Declaration>///
int life = 500;
float sec = 0;
float degree;
sf::RenderWindow window(sf::VideoMode(1920, 1080), "Mark Lee Die D Die", sf::Style::Close | sf::Style::Fullscreen);
float randowplatform(float , float);
///<START MAIN>///
int main()
{
	srand(time(NULL));
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(false);
	sf::Vector2f size(100.0f, 100.0f);
	sf::RectangleShape test;
	test.setSize(sf::Vector2f(1000.0f, 200.0f));
	test.setPosition(750.0f, window.getSize().y - test.getSize().y - 300);
	test.setFillColor(sf::Color::Red);

	//time control 
	sf::Clock clock;
	float deltatime = 0.0f;
	float offsetYplayer = 0;

	//for declare texture
	sf::Texture ptexture;
	ptexture.loadFromFile("fox.png");

	sf::Texture marklee;
	marklee.loadFromFile("Enemy/Enemy.png");

	sf::Texture tbackground;
	tbackground.loadFromFile("Background/Background.png");

	//For declare everything
	int row = 0;
	float ground = 750.0;
	int enemycount = 0;
	float timerforplatform[3]{5,8,10};

	//For declare bullet
	sf::Vector2f playercenter;
	sf::Vector2f mouseposition;
	sf::Vector2f aimdirection;
	sf::Vector2f aimdirectionnorm;
	sf::Vector2f velocitybullet;

	//declare movingthing
	Player player1(&ptexture, sf::Vector2u(5, 5), 100.0f);
	Background_move Background_move(&tbackground);

	sf::RectangleShape enemy;
	enemy.setTexture(&marklee);
	enemy.setSize(sf::Vector2f(86.0f, 202.0f));
	enemy.setTextureRect(sf::IntRect(0, 0, 86, 202));
	enemy.setOrigin(enemy.getSize().x / 2, enemy.getSize().y / 2);


	// declare class for text
	Texteiei Text1;
	Texteiei Text2;
	Texteiei Text3;

	//Platform
	sf::Texture plattexture;
	sf::Texture plattexture2;
	sf::Texture plattexture3;
	plattexture3.loadFromFile("Platform/Platform3.png");
	plattexture2.loadFromFile("Platform/Platform2_fix.png");
	plattexture.loadFromFile("Platform/Platform.png");

	Platform platform1(&plattexture, sf::Vector2f(plattexture.getSize().x / 3, plattexture.getSize().y), 20, 300, sf::Vector2f(sec*100, 1000.0f));
	Platform platform2(&plattexture2, sf::Vector2f(plattexture2.getSize().x / 3, plattexture2.getSize().y), 0, 200, sf::Vector2f(sec*100, 800.0f));
	Platform platform3(&plattexture3, sf::Vector2f(plattexture3.getSize().x / 3, plattexture3.getSize().y), 20, 500, sf::Vector2f(sec*100, 700.0f));
	std::vector<Platform> platforms;
	


	Bullet bullet;
	short int enemyspawntimer = 0;
	short int bulletspawntimer = 0;
	short int platformnum = 0;

	std::vector<RectangleShape> enemies;
	std::vector<Bullet> bullets;
	bool flag1 = false;
	///<START GAME LOOP>
	while (window.isOpen() )
	{
		deltatime = clock.restart().asSeconds();
		player1.onground = false;
		sf::Event evnt;
		if (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyReleased:
				if (sf::Keyboard::A || sf::Keyboard::D)
				{
					player1.row = 4;
				}


			}
			if (evnt.type == evnt.Closed)
			{
				window.close();
			}
		}


		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			///...<UPDATE GAME VALUE>...

			degree = atan2(mouseposition.y - player1.getcenter().y, mouseposition.x - player1.getcenter().x) * (180 / 3.141);
			sec += deltatime;

			///...<KEYBOARD BUFFER>...
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) { window.close(); }

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

			Background_move.background_update(deltatime);
			player1.update(deltatime, ground, degree);
			player1.moveplayer();

			if ((int)sec == 1 and flag1 == 0)
			{
				platforms.push_back(Platform(platform1));
				flag1 = true;
			}
			if ((int)sec == 4 and flag1 == 1)
			{
				platforms.push_back(Platform(platform2));
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
					platforms[i].speed = 70;
				}
				if (platforms[i].lifetime <= 0)
				{
					platforms.erase(platforms.begin() + i);
					platformnum++;
					switch (platformnum % 3)
					{
					case 0:
						platforms.push_back(Platform(&plattexture, sf::Vector2f(plattexture.getSize().x / 3, plattexture.getSize().y), 20, 300, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 1000.0f)));
						break;
					case 1:
						platforms.push_back(Platform(&plattexture2, sf::Vector2f(plattexture2.getSize().x / 3, plattexture2.getSize().y), 0, 200, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 800.0f)));
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
						and player1.getright() < platforms[i].hitbox.getGlobalBounds().left + 25
						) {
						player1.dx = 0.0f;
						player1.player_clone.left = platforms[i].hitbox.getGlobalBounds().left - player1.player_clone.width;
					}

					///<Left>///
					else if (player1.getleft() <= platforms[i].hitbox.getGlobalBounds().left + platforms[i].hitbox.getGlobalBounds().width
						and player1.getleft() > platforms[i].hitbox.getGlobalBounds().left + platforms[i].hitbox.getGlobalBounds().width - 25
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

			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			{
				if (player1.onground)
				{
					player1.onground = false;
					player1.dy = -30;
				}
			}

			//Update Bullet Direction
			playercenter = sf::Vector2f(player1.player_clone.left + player1.currentframe.x / 2, player1.player_clone.top + player1.currentframe.y / 2);
			mouseposition = sf::Vector2f(sf::Mouse::getPosition(window));
			aimdirection = mouseposition - playercenter;
			aimdirectionnorm = aimdirection / sqrt(pow(aimdirection.x, 2) + (pow(aimdirection.y, 2)));
			std::cout << aimdirectionnorm.x << "    " << -aimdirectionnorm.y << endl;

			//Enemy update

			if (enemyspawntimer < 10) { enemyspawntimer++; }

			if (enemyspawntimer == 10)
			{
				enemy.setPosition(sf::Vector2f(rand() % window.getSize().x, 0));
				enemies.push_back(RectangleShape(enemy));
				enemyspawntimer = 0;
			}
			//Checkshot
			for (size_t i = 0; i < enemies.size(); i++)
			{
				for (size_t k = 0; k < bullets.size(); k++)
				{
					if (enemies[i].getGlobalBounds().intersects(bullets[k].shape.getGlobalBounds()))
					{
						enemycount++;
						enemies.erase(enemies.begin() + i);
						bullets.erase(bullets.begin() + k);
						break;
					}
				}
			}
			//Enemies Out of Bound
			for (size_t i = 0; i < enemies.size(); i++)
			{
				sf::Vector2f enemymovement;
				enemies[i].setRotation(cos(i));
				if (enemies[i].getPosition().x + enemies[i].getSize().x / 2.0f > player1.getcenter().x)
				{
					enemymovement.x = -1 * deltatime * (rand() % (200 - 100) + 100);
				}
				else
				{
					enemymovement.x = 1 * deltatime * (rand() % (200 - 100) + 100);

				}
				enemies[i].move(enemymovement.x, 3);
				if (enemies[i].getPosition().y > 1000)
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
				if (bullets[k].shape.getPosition().y < 0 or bullets[k].shape.getPosition().y > window.getSize().y or bullets[k].shape.getPosition().x < 0 or bullets[k].shape.getPosition().x > window.getSize().x)
				{
					bullets.erase(bullets.begin() + k);
				}
			}
			///<START DRAWING>///

			window.clear();

			Background_move.draw(window);

			for (size_t i = 0; i < enemies.size(); i++)
			{
				window.draw(enemies[i]);
			}
			for (size_t i = 0; i < bullets.size(); i++)
			{
				bullets[i].draw(window);
			}
			for (size_t i = 0; i < platforms.size(); i++) { platforms[i].Draw(window); }
			player1.draw(window);
			//Draw text
			Text1.text1(randowplatform(player1.getright(), rand() % 2), window, sf::Vector2f(0.0f, 0.0f), (string)"Timerplatform 0: ");
			Text2.text1(platforms[0].lifetime, window, sf::Vector2f(0.0f, 150.0f), (string)"Timerplatform 1: ");
			Text3.text1(platforms[0].lifetime, window, sf::Vector2f(1000.0f, 0.0f), (string)"Timerplatform 2: ");

			window.display();
		}
	}
	return (0);

}

float randowplatform(float posiX , float sizeX)
{
	float size = posiX + sizeX;
	if (size <= window.getSize().x / 2)
	{
		return rand() % ((int)window.getSize().x - (int)sizeX) + sizeX;
	}
	else if (size >= window.getSize().x / 2)
	{
		return rand() % ((int)window.getSize().x - (int)sizeX) + sizeX;
	}

}










