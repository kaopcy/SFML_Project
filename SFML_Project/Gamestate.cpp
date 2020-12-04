#include "Gamestate.h"
Gamestate::Gamestate(sf::RenderWindow* window) :
	State(window),
	bulletoni(10.0),
	bullet(25.0),
	player1(1, sf::Vector2u(6, 11), 100.0f),
	enemy1(1, 4, sf::Vector2u(4, 2)),
	background1(tbackground)
	
{
	this->platforms.push_back(Platform(&plattexture, sf::Vector2f(plattexture.getSize().x / 3, plattexture.getSize().y), 0, 300, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 1000.0f), rand() % 2));
	this->platforms.push_back(Platform(&plattexture2, sf::Vector2f(plattexture2.getSize().x / 3, plattexture2.getSize().y), 20, 200, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 800.0f), rand() % 2));
	this->plattexture3.loadFromFile("Platform/Platform3.png");
	this->plattexture2.loadFromFile("Platform/Platform1.png");
	this->plattexture.loadFromFile("Platform/Platform2_fix.png");
	this->Tsplashitachi.loadFromFile("splash/itachisplash.png");
	this->shuriken_big.loadFromFile("shuriken/shuriken_big.png");
	this->shuriken_big.setSmooth(true);
	this->splashitachi.setTexture(Tsplashitachi);
	this->splashitachi.setPosition(window->getSize().x / 2 - 250, window->getSize().y / 2);
	this->splashitachi.setOrigin((Tsplashitachi.getSize().x / 10) / 2, (Tsplashitachi.getSize().y) / 2);
	Tsplashitachi.setSmooth(true);

	this->splashitachi1.setTexture(Tsplashitachi);
	this->splashitachi1.setPosition(window->getSize().x / 2 + 250, window->getSize().y / 2);
	this->splashitachi1.setOrigin((Tsplashitachi.getSize().x / 10) / 2, (Tsplashitachi.getSize().y) / 2);
	this->soundeffect.soundbackground();
	
}

Gamestate::~Gamestate()
{
}

void Gamestate::updatedt(const float& deltatime)
{
	this->sec += deltatime;
}

void Gamestate::endstate()
{
	cout << "end state " << endl;
}

void Gamestate::updatekeybind(const float& deltatime, sf::Event& evnt)
{
	//When release
	if (sf::Event::KeyReleased)
	{
		switch (evnt.key.code)
		{
		case sf::Keyboard::Q:
			onceSwitchWeapon = true;
			break;
		case sf::Keyboard::V:
			break;
		


		}
	}

	this->checkforquit();
	this->KeybindShuriken();
	//When keypressed
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) and !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->player1.dx = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		if (this->player1.onground)
		{
			if (this->player1.sharingan)
			{
				this->player1.onground = false;
				this->player1.dy = -15;
			}
			else
			{
				this->player1.onground = false;
				this->player1.dy = -30;
			}
			
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		playerpositionbeforeteleport.y = player1.player_clone.top;
		slash = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (bulletspawntimer < bullet.reload) { bulletspawntimer++; }
		if (bulletspawntimer == bullet.reload and bullets.size() < 100)
		{
			if (sf::Mouse::getPosition().x > player1.getcenter().x)
				player1.row = 7;
			else
				player1.row = 9;
			bullet.shape.setPosition(player1.getcenter());
			bullet.currentvelocity = aimdirectionnorm * bullet.speed;
			bullets.push_back(Bullet(bullet));
			bulletspawntimer = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		player1.sharingan = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		if (setmouseposiforteleport)
		{
			mouseposiforteleport.x = sf::Mouse::getPosition().x;
			mouseposiforteleport.y = sf::Mouse::getPosition().y;
			playerpositionbeforeteleport.x = player1.player_clone.left;
			playerpositionbeforeteleport.y = player1.player_clone.top;

			setmouseposiforteleport = false;
		}


		if (player1.onground)
		{
			player1.onground = false;
		}
		teleport = true;


	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		if (!teleport and !slash)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
			{
				player1.dx = -1;
				player1.speed = 5000;
				cout << "run";
				if (!itachisharingan and !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))

				player1.row = 2;

			}
			else
			{

				player1.speed = 400;
				player1.dx = -1;
				if (!itachisharingan and !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))

				player1.row = 4;
			}
		}

	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		if (!teleport and !slash)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
			{
				player1.dx = 1;
				player1.speed = 5000;
				cout << "run";
				if(!itachisharingan and !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				player1.row = 1;

			}
			else
			{

				player1.speed = 400;
				player1.dx = 1;
				if (!itachisharingan and !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				player1.row = 3;
			}
		}


	}
	else
	{
		if (!itachisharingan and !teleport and !slash and !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			this->player1.row = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) and onceSwitchWeapon)
	{
		player1.weaponInput++;
		onceSwitchWeapon = false;
	}
	

}

void Gamestate::update(const float& deltatime, sf::Event& evnt)
{
	this->oni.update(deltatime, background1.getGround() , player1.getcenter());
	this->BossShoot();
	this->soundeffect.playMangekyoSound(slash);
	this->soundeffect.playsharingansound(player1.sharingan);
	this->soundeffect.playTeleportsound(teleport);
	this->skill(deltatime);
	this->updatedt(deltatime);
	this->updatekeybind(deltatime, evnt);
	player1.onground = false;
	this->background1.background_update(deltatime, player1.sharingan, slash);
	player1.update(deltatime, degree , ultimate);
	player1.moveplayer();
	this->platformUpdate(deltatime);
	if (player1.getbot() > background1.getGround())
	{
		player1.player_clone.top = background1.getGround() - player1.player_clone.height;
		player1.onground = true;
	}



	//Update Bullet Direction
	this->Degreecalculate();

	//Enemy update
	if (!player1.sharingan)
	{

		if (enemyspawntimer < 10) { enemyspawntimer++; }

		if (enemyspawntimer == 10)
		{
			enemy1.hitbox.setPosition(sf::Vector2f(rand() % window->getSize().x, -(enemy1.hitbox.getSize().y)));
			enemies.push_back(Enemy(enemy1));
			enemyspawntimer = 0;
		}
	}
	for (size_t i = 0; i < shurikenbigs.size(); i++)
	{
		shurikenbigs[i].update(deltatime, aimdirectionnorm , player1.sharingan);
	}
	//Checkshot
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (slash and !enemies[i].dead)
		{
			enemies[i].dead = true;
		}
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
		for (size_t j = 0; j < shurikenbigs.size(); j++)
		{
			if (shurikenbigs[j].getshape().intersects(enemies[i].hitbox.getGlobalBounds()))
			{
				enemies[i].dead = true;
				enemycount++;
			}
		}
		enemies[i].update(deltatime, slash);


		if (slow)
		{
			enemies[i].dy = 0.5;
			enemies[i].dx *= 0.5;
		}
		else
		{
			enemies[i].dy = 4;
		}

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
		bullets[k].update(deltatime, player1.sharingan);
		if (slow)
			bullets[k].shape.move(bullets[k].currentvelocity.x * 0.1, bullets[k].currentvelocity.y * 0.1);
		else
			bullets[k].shape.move(bullets[k].currentvelocity.x * 1, bullets[k].currentvelocity.y * 1);

		if (bullets[k].shape.getPosition().y < 0 or bullets[k].shape.getPosition().y > window->getSize().y or bullets[k].shape.getPosition().x < 0 or bullets[k].shape.getPosition().x > window->getSize().x)
		{
			bullets.erase(bullets.begin() + k);
		}
	}
	for (size_t k = 0; k < oniBullets.size(); k++)
	{
		oniBullets[k].update(deltatime, player1.sharingan);
		if (slow)
			oniBullets[k].shape.move(oniBullets[k].currentvelocity.x * 0.1, oniBullets[k].currentvelocity.y * 0.1);
		else
			oniBullets[k].shape.move(oniBullets[k].currentvelocity.x * 1, oniBullets[k].currentvelocity.y * 1);

		if (oniBullets[k].shape.getPosition().y < 0 or oniBullets[k].shape.getPosition().y > window->getSize().y or oniBullets[k].shape.getPosition().x < 0 or oniBullets[k].shape.getPosition().x > window->getSize().x)
		{
			oniBullets.erase(oniBullets.begin() + k);
		}
	}
}

void Gamestate::platformUpdate(const float& deltatime)
{
	if ((int)sec == 1 and flag1 == 0)
	{
		platformnum++;
		flag1 = true;
	}
	if ((int)sec == 3 and flag1 == 1)
	{
		platforms.push_back(Platform(&plattexture2, sf::Vector2f(plattexture2.getSize().x / 3, plattexture2.getSize().y), 20, 200, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 900.0f), rand() % 2));
		platformnum++;
		flag1 = false;
	}
	if (!slow)
	{

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
					platforms.push_back(Platform(&plattexture, sf::Vector2f(plattexture.getSize().x / 3, plattexture.getSize().y), 0, 300, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 1000.0f), rand() % 2));
					break;
				case 1:
					platforms.push_back(Platform(&plattexture2, sf::Vector2f(plattexture2.getSize().x / 3, plattexture2.getSize().y), 20, 200, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 800.0f), rand() % 2));
					break;
				case 2:
					platforms.push_back(Platform(&plattexture3, sf::Vector2f(plattexture3.getSize().x / 3, plattexture3.getSize().y), 20, 500, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 900.0f), rand() % 2));
					break;
				}
				break;
			}
			platforms[i].Update(deltatime);

		}
	}

	for (size_t i = 0; i < platforms.size(); i++)
	{
		if (!slow)
			platforms[i].moving((float)1.0, deltatime);
		else
			platforms[i].moving((float)0.1, deltatime);

		
			///<Right>///
			if (player1.getright() >= platforms[i].hitbox.getGlobalBounds().left
				and player1.getright() < platforms[i].hitbox.getGlobalBounds().left + 35 and player1.getbot() > platforms[i].hitbox.getGlobalBounds().top
				) {
				player1.dx = 0.0f;
				player1.player_clone.left = platforms[i].hitbox.getGlobalBounds().left - player1.player_clone.width;
			}

			///<Left>///
			else if (player1.getleft() <= platforms[i].hitbox.getGlobalBounds().left + platforms[i].hitbox.getGlobalBounds().width
				and player1.getleft() > platforms[i].hitbox.getGlobalBounds().left + platforms[i].hitbox.getGlobalBounds().width - 35
				and player1.getbot() > platforms[i].hitbox.getGlobalBounds().top
				) {
				player1.dx = 0.0f;
				player1.player_clone.left = platforms[i].hitbox.getGlobalBounds().left + platforms[i].hitbox.getGlobalBounds().width;
			}

			///<Top>///
			else if (player1.getbot() > platforms[i].hitbox.getGlobalBounds().top
				and player1.getright() > platforms[i].hitbox.getGlobalBounds().left
				and player1.player_clone.left < platforms[i].hitbox.getGlobalBounds().left + platforms[i].hitbox.getGlobalBounds().width
				) {
				player1.player_clone.top = platforms[i].hitbox.getGlobalBounds().top - player1.player_clone.height;
				player1.onground = true;
				player1.dy = 0;

			}
		
			if (player1.onground and player1.getright() > platforms[i].getleft())
			{

			}


	}
}

void Gamestate::Degreecalculate()
{
	degree = atan2(mouseposition.y - player1.getcenter().y, mouseposition.x - player1.getcenter().x) * (180 / 3.141);
	playercenter = sf::Vector2f(player1.player_clone.left + player1.currentframe.x / 2, player1.player_clone.top + player1.currentframe.y / 2);
	mouseposition = sf::Vector2f(sf::Mouse::getPosition(*window));
	aimdirection = mouseposition - playercenter;
	aimdirectionnorm = aimdirection / sqrt(pow(aimdirection.x, 2) + (pow(aimdirection.y, 2)));
}

void Gamestate::render(sf::RenderWindow& window)
{
	this->background1.draw(window, player1.sharingan, slash);
	if (player1.sharingan and sharinganeyetime >= 0)
	{
		window.draw(this->splashitachi);
		window.draw(this->splashitachi1);



	}

	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].draw(window);
		this->enemies[i].drawexplode(window);
	}
	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i].draw(window);
	}
	for (size_t i = 0; i < this->oniBullets.size(); i++)
	{
		this->oniBullets[i].draw(window);
	}
	for (size_t i = 0; i < platforms.size(); i++) { platforms[i].Draw(window); }

	for (size_t i = 0; i < this->shurikenbigs.size(); i++)
	{
		shurikenbigs[i].draw(window);
	}
	player1.draw(window);
	oni.draw(window);
	drawtext(window);
}

void Gamestate::drawtext(sf::RenderWindow& window)
{
	Text3.numberwithtext(window, oni.aimdirectionnorm.x, (string)"Timer : ", 100.0f, sf::Vector2f(1300.0f, 0.0f), sf::Vector3i(247, 129, 232));
}

void Gamestate::skill(const float& deltatime)
{

	if (player1.sharingan)
	{
		itachisharingan = true;
		if (player1.sharingantimer >= 0.75 and itachisharingan)
		{
			player1.row = 8;
		}
		else
			itachisharingan = false;
		animationsharingan(deltatime);
		slow = true;
		player1.sharingantimer -= deltatime;
		splashitachi.setRotation(itachirotation += 5);
		splashitachi1.setRotation(itachirotation += 5);
		if (sharinganeyetime <= 0.75)
		{
			splashitachi.setRotation(0);
			splashitachi1.setRotation(0);

		}

		if (player1.sharingantimer <= 0)
		{
			player1.sharingantimer = 5;
			slow = false;
			itachiscale = 1;
			player1.sharingan = false;
			sharinganeyetime = 2;
		}
	}

	if (teleport)
	{
		player1.row = 5;
		player1.player_clone.top = playerpositionbeforeteleport.y;
		player1.player_clone.left = playerpositionbeforeteleport.x;

		if (teleporttimer >= 0.5)
		{
			player1.player_clone.top = mouseposiforteleport.y;
			player1.player_clone.left = mouseposiforteleport.x;

		}


		teleporttimer += deltatime;
		if (teleporttimer >= 0.9)
		{
			teleporttimer = 0;
			teleport = false;
			setmouseposiforteleport = true;

		}

	}
	if (slash)
	{
		player1.player_clone.top = playerpositionbeforeteleport.y;
		player1.row = 6;
		slashtimer += deltatime;
		if (slashtimer >= 0.9)
		{
			soundeffect.playDeadSound(1);
			slashtimer = 0;
			slash = false;
		}
		


	}
}

void Gamestate::animationsharingan(const float& deltatime)
{
	splashitachi.setTextureRect(sf::IntRect((Tsplashitachi.getSize().x / 10) * sharinguneye, 0, Tsplashitachi.getSize().x / 10, Tsplashitachi.getSize().y));
	splashitachi1.setTextureRect(sf::IntRect((Tsplashitachi.getSize().x / 10) * sharinguneye, 0, Tsplashitachi.getSize().x / 10, Tsplashitachi.getSize().y));

	offsetsharingan += deltatime;
	sharinganeyetime -= deltatime;
	if (offsetsharingan >= 0.15)
	{
		offsetsharingan -= 0.15;
		sharinguneye++;
	}

	if (sharinguneye >= 10)
	{
		sharinguneye = 9;
	}
}

void Gamestate::BossShoot()
{
	if (oni.BulletSpawnTimer < oni.BulletReload) { oni.BulletSpawnTimer++; }
	if (oni.BulletSpawnTimer == oni.BulletReload and oniBullets.size() < 100)
	{
		bulletoni.shape.setPosition(oni.aimDirect());
		bulletoni.currentvelocity = oni.aimdirectionnorm * bulletoni.speed;
		oniBullets.push_back(Bullet(bulletoni));
		oni.BulletSpawnTimer = 0;
	}
}

void Gamestate::KeybindShuriken()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V))
	{
		throwshuriken = true;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V) and throwshuriken)
	{
		shurikenbigs.push_back(Shuriken(shuriken_big, player1.getcenter(), aimdirectionnorm));
		throwshuriken = false;
	}
}

void Gamestate::updateShuriken()
{
}

void Gamestate::ultimatefunc(const float& deltatime)
{
}

float Gamestate::randowplatform(float posiX, float sizeX)
{
	float size = posiX + (sizeX / 2);
	if (size <= window->getSize().x / 2)
	{
		return rand() % ((int)window->getSize().x / 2 - (int)sizeX) + sizeX;
	}
	else if (size >= window->getSize().x / 2)
	{
		return rand() % ((int)window->getSize().x - ((int)window->getSize().x / 2 + (int)sizeX)) + ((int)window->getSize().x / 2 + (int)sizeX);
	}

}
