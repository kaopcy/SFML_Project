#include "Gamestate.h"
#define Window_height 1080
#define Window_width 1920
#define Game_width 3000
#define Game_height 1080

Gamestate::Gamestate(sf::RenderWindow* window) :
	State(window),
	bullet(tbullet , 10.0 ,1),
	bulletoni(tFireball , 10.0 , 2),
	player1(1, sf::Vector2u(6, 14), 100.0f),
	enemy1(Texplode,Etexture , 1, 4, sf::Vector2u(4, 2) , sf::Vector2f(getRand().x,0)),
	background1(tbackground),
	oni(sf::Vector2f(1000,100)),
	oni2(sf::Vector2f(100, 100))

{
	this->Etexture.loadFromFile("Enemy/Golem.png");
	this->Etexture.setSmooth(true);
	this->Texplode.loadFromFile("Explode/Explode.png");
	this->Texplode.setSmooth(true);
	

	this->platforms.push_back(Platform(&plattexture, sf::Vector2f(plattexture.getSize().x / 3, plattexture.getSize().y), 0, 300, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 1000.0f), rand() % 2));
	this->platforms.push_back(Platform(&plattexture2, sf::Vector2f(plattexture2.getSize().x / 3, plattexture2.getSize().y), 20, 200, sf::Vector2f(randowplatform(player1.getright(), player1.getglobalbound().width), 800.0f), rand() % 2));
	this->plattexture3.loadFromFile("Platform/Platform3.png");
	this->plattexture2.loadFromFile("Platform/Platform1.png");
	this->plattexture.loadFromFile("Platform/Platform2_fix.png");
	this->Tsplashitachi.loadFromFile("splash/itachisplash.png");
	this->shuriken_big.loadFromFile("shuriken/shuriken_big.png");
	this->shuriken_big.setSmooth(true);
	this->splashitachi.setTexture(Tsplashitachi);
	this->splashitachi.setOrigin((Tsplashitachi.getSize().x / 10) / 2, (Tsplashitachi.getSize().y) / 2);
	this->Tsplashitachi.setSmooth(true);

	this->splashitachi1.setTexture(Tsplashitachi);
	this->splashitachi1.setPosition(window->getSize().x / 2 + 250, window->getSize().y / 2);
	this->splashitachi1.setOrigin((Tsplashitachi.getSize().x / 10) / 2, (Tsplashitachi.getSize().y) / 2);
	this->soundeffect.soundbackground();
	this->view.setSize(sf::Vector2f(1920, 1080));



	

	for (size_t i = 0; i <= 9; i++)
	{
		canUseSkill[i] = true;
	}

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
		


		}
	}

	this->checkforquit();
	this->KeybindShuriken();
	//When keypressed
	if (player1.dy != 0 and !teleport and !slash and !throwshuriken and !player1.isShield and !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) and !player1.onground)
	{
		jumping = true;
	}
	else
		jumping = false;
	if (jumping)
	{
		player1.row = 13;
	}
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
				this->player1.dy = -10.5;
			}
			else
			{
				this->player1.onground = false;
				this->player1.dy = -20;
			}
			
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		player1.row = 12;
		player1.isShield = true;
	}

	else
		player1.isShield = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) and canUseSkill[1] and !player1.isShield)
	{
		player1.enegyFlow -= 10;
		playerpositionbeforeteleport.y = player1.player_clone.top;
		slash = true;
		canUseSkill[1] = false;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) and !player1.isShield)
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) and canUseSkill[0] and !player1.isShield)
	{
		player1.sharingan = true;
		player1.enegyFlow -= 90;
		canUseSkill[0] = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) and !player1.isShield)
	{
		if (setmouseposiforteleport)
		{
			mouseposiforteleport.x = mouseposition.x;
			mouseposiforteleport.y = mouseposition.y;
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


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) and !slash)
	{
		if (!teleport and !slash and !throwshuriken and !player1.isShield)
		{
			player1.faceRight = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
			{
				player1.dx = -1;
				player1.speed = 700;
				cout << "run";
				if (!itachisharingan and !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) and !jumping)

				player1.row = 2;

			}
			else
			{

				player1.speed = 400;
				player1.dx = -1;
				if (!itachisharingan and !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) and !jumping)

				player1.row = 4;
			}
		}

	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) and !slash)
	{
		if (!teleport and !slash and !throwshuriken and !player1.isShield)
		{
			player1.faceRight = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
			{
				player1.dx = 1;
				player1.speed = 700;
				cout << "run";
				if(!itachisharingan and !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) and !jumping)
				player1.row = 1;

			}
			else
			{

				player1.speed = 400;
				player1.dx = 1;
				if (!itachisharingan and !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) and !jumping)
				player1.row = 3;
			}
		}


	}
	else
	{
		if (!itachisharingan and !teleport and !slash and !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) and !throwshuriken and !player1.isShield and !jumping)
			this->player1.row = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) and onceSwitchWeapon)
	{
		player1.weaponInput++;
		onceSwitchWeapon = false;
		this->onies.push_back(Boss(oni));
		this->enemies.push_back(Enemy(Texplode, Etexture, 1, 10, sf::Vector2u(7, 5) , sf::Vector2f(getRand().x , 0)) );
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		gameOver = true;
	}

}

void Gamestate::update(const float& deltatime, sf::Event& evnt)
{
	cout << background1.getGround()<< endl;
	this->manaManagement();
	for(size_t i = 0 ; i < onies.size() ; i++)
	this->onies[i].update(deltatime, background1.getGround() , player1.getcenter());
	this->hitBoss();
	this->reflect();
	this->BossShoot();
	this->viewControl();
	this->soundeffect.playMangekyoSound(slash);
	this->soundeffect.playsharingansound(player1.sharingan);
	this->soundeffect.playTeleportsound(teleport);
	this->skill(deltatime);
	this->updatedt(deltatime);
	this->updatekeybind(deltatime, evnt);
	player1.onground = false;
	this->background1.background_update(deltatime, player1.sharingan, slash , player1.getcenter());
	player1.update(deltatime, degree , ultimate ,sf::Vector2f((float)View_left() , (float)View_top()));
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
	
	for (size_t i = 0; i < shurikenbigs.size(); i++)
	{
		shurikenbigs[i].update(deltatime, aimdirectionnorm , player1.sharingan, throwshuriken , player1.getcenter());
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
		enemies[i].update(deltatime, slash , background1.getGround());

		if (slow and !enemies[i].changePhases)
		{
			enemies[i].dy = 0.5;
			enemies[i].dx *= 0.5;
		}
		else if (!slow and !enemies[i].changePhases)
		{
			enemies[i].dy = 4;
		}

		if ((enemies[i].lifetime <= 0 and enemies[i].dead) or enemies[i].erase )
		{
			enemies.erase(enemies.begin() + i);
		}
	}

	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].hitbox.getGlobalBounds().intersects(player1.getglobalbound()) and !enemies[i].dead)
		{
			player1.hp--;
			enemies[i].dead = true;
			if (player1.hp <= 0)
			{
				player1.hp = 10;
			}
		}
	}

	//Enemies Out of Bound
	
	//Update Bullet
	for (size_t k = 0; k < bullets.size(); k++)
	{
		bullets[k].update(deltatime, player1.sharingan);
		if (slow)
			bullets[k].shape.move(bullets[k].currentvelocity.x * 0.1, bullets[k].currentvelocity.y * 0.1);
		else
			bullets[k].shape.move(bullets[k].currentvelocity.x * 1, bullets[k].currentvelocity.y * 1);

		if (bullets[k].shape.getPosition().y < 0 or bullets[k].shape.getPosition().y > Game_height or bullets[k].shape.getPosition().x < 0 or bullets[k].shape.getPosition().x > Game_width)
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

		if (oniBullets[k].shape.getPosition().y < 0 or oniBullets[k].shape.getPosition().y > Game_height or oniBullets[k].shape.getPosition().x < 0 or oniBullets[k].shape.getPosition().x > Game_width)
		{
			oniBullets.erase(oniBullets.begin() + k);
			break;
		}

		for (size_t j = 0; j < shurikenbigs.size(); j++)
		{
			if (shurikenbigs[j].getshape().intersects(oniBullets[k].shape.getGlobalBounds()))
			{
				oniBullets.erase(oniBullets.begin() + k);
				break;
			}
		}
	}
	//loop for check Explode
	for (size_t i = 0; i < explodeEffects.size(); i++)
	{
		explodeEffects[i].update(deltatime);
		if (explodeEffects[i].lifeTime)
		{
			explodeEffects.erase(explodeEffects.begin() + i);
			break;
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
	beforeMousePos = sf::Vector2f(sf::Mouse::getPosition(*window));
	mouseposition = window->mapPixelToCoords(sf::Vector2i(beforeMousePos));
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
	for (size_t i = 0; i < platforms.size(); i++) { platforms[i].Draw(window); }

	for (size_t i = 0; i < this->shurikenbigs.size(); i++)
	{
		shurikenbigs[i].draw(window);
	}
	for (size_t i = 0; i < this->oniBullets.size(); i++)
	{
		this->oniBullets[i].draw(window);
	}
	player1.draw(window);
	for (size_t i = 0; i < onies.size(); i++)
	{
		onies[i].draw(window);
	}
	for (size_t i = 0; i < explodeEffects.size(); i++)
	{
		explodeEffects[i].draw(window);
	}
	//drawtext(window);
	window.setView(this->view);
}

void Gamestate::drawtext(sf::RenderWindow& window)
{
	Text3.numberwithtext(window, oni.knockback, (string)"Timer : ", 100.0f, sf::Vector2f(1300.0f, 0.0f), sf::Vector3i(247, 129, 232));
	
}

void Gamestate::skill(const float& deltatime)
{

	if (player1.sharingan)
	{
		itachisharingan = true;
		if (player1.sharingantimer >= 0.75 and itachisharingan)
		{
			player1.row = 8;
			for (size_t i = 0; i < onies.size(); i++)
			{
				onies[i].Movespeed = 30;
			}
		}
		else
		{
			itachisharingan = false;
			for (size_t i = 0; i < onies.size(); i++)
			{
				onies[i].Movespeed = 100;
			}
		}
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
			canUseSkill[0] = true;
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
		player1.dy = -15;
		player1.onground = false;

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
		player1.dx = 0;
		if (!player1.onground)
		{
			player1.dy = -10.5;
		}
		player1.row = 6;
		slashtimer += deltatime;
		if (slashtimer >= 0.9)
		{
			soundeffect.playDeadSound(1);
			slashtimer = 0;
			slash = false;
			player1.onground = false;
		}
		


	}
}

void Gamestate::animationsharingan(const float& deltatime)
{
	splashitachi.setTextureRect(sf::IntRect((Tsplashitachi.getSize().x / 10) * sharinguneye, 0, Tsplashitachi.getSize().x / 10, Tsplashitachi.getSize().y));
	splashitachi1.setTextureRect(sf::IntRect((Tsplashitachi.getSize().x / 10) * sharinguneye, 0, Tsplashitachi.getSize().x / 10, Tsplashitachi.getSize().y));
	this->splashitachi.setPosition(view.getCenter().x - 250, view.getCenter().y);

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
	for (size_t i = 0; i < onies.size(); i++)
	{
		if (onies[i].BulletSpawnTimer < onies[i].BulletReload) { onies[i].BulletSpawnTimer++; }
		if (onies[i].BulletSpawnTimer >= onies[i].BulletReload and oniBullets.size() < 50)
		{
			bulletoni.shape.setPosition(onies[i].aimDirect());
			bulletoni.currentvelocity = onies[i].aimdirectionnorm * onies[i].bulletSpeed;
			
			oniBullets.push_back(Bullet(bulletoni));
			onies[i].BulletSpawnTimer = 0;
		}
	}
	
}

void Gamestate::reflect()
{
	for (size_t i = 0; i < oniBullets.size(); i++)
	{
		if (oniBullets[i].shape.getGlobalBounds().intersects(player1.hitbox.getGlobalBounds()))
		{
			if (player1.isShield)
			{
				oniBullets[i].currentvelocity.x = -(oniBullets[i].currentvelocity.x);
				oniBullets[i].currentvelocity.y = -(oniBullets[i].currentvelocity.y);
			}
			else
			{
				oniBullets.erase(oniBullets.begin() + i);
				player1.hpFlow--;
			}
		}
	}
}

void Gamestate::hitBoss()
{
	for (size_t j = 0; j < onies.size(); j++)
	{
		for (size_t i = 0; i < bullets.size(); i++)
		{
				if (bullets[i].shape.getGlobalBounds().intersects(onies[j].hitbox.getGlobalBounds())  and !onies[j].healSkill)
				{
					onies[j].hpFlow -= 1;
					bullets.erase(bullets.begin() + i);
					break;
				}
				if (onies[j].hpFlow <= 0)
				{
					onies.push_back(Boss(sf::Vector2f(onies[j].getCenter().x + 300, onies[i].getCenter().y)));
					onies.push_back(Boss(sf::Vector2f(onies[j].getCenter().x - 300, onies[i].getCenter().y)));
					onies.erase(onies.begin() + j);
					break;
				}
				if (bullets[i].shape.getGlobalBounds().intersects(onies[j].hitbox.getGlobalBounds()) and onies[j].healSkill)
				{
					onies[j].hpFlow += 5;
					bullets.erase(bullets.begin() + i);
					break;
				}
		}	
		
	}
	for (size_t j = 0; j < onies.size(); j++)
	{
		for (size_t k = 0; k < shurikenbigs.size(); k++)
		{
			if (shurikenbigs[k].getshape().intersects(onies[j].hitbox.getGlobalBounds()))
			{
				explodeEffects.push_back(ExplodeEffect(sf::Vector2f(this->onies[j].getCenter()), 1, Texplode));
				onies[j].knockback = true;
				shurikenbigs.erase(shurikenbigs.begin() + k);
				break;
			}
		}
	}
	
}

void Gamestate::viewControl()
{
	if (slash)
	{
		if (!flagViewCenter)
		{
			lastView = view.getCenter();
			flagViewCenter = true;
		}

		view.setCenter(rand() % (((int)lastView.x+15) - ((int)lastView.x-15 )) + (int)lastView.x - 15 , rand() % (((int)lastView.y + 10) - ((int)lastView.y - 1)) + (int)lastView.y - 10);
		cout << "ikuat";
	}
	if (!slash and flagViewCenter)
	{
		view.setCenter(lastView);
		flagViewCenter = false;
	}
	if(!flagViewCenter)
	{
		if (player1.getcenter().x > view.getCenter().x + window->getSize().x * 0.25 and View_right() < Game_width)
			this->view.setCenter(sf::Vector2f(player1.getcenter().x - window->getSize().x * 0.25, window->getSize().y / 2));
		if (player1.getcenter().x < view.getCenter().x - window->getSize().x * 0.25 and View_left() > 0)
			this->view.setCenter(sf::Vector2f(player1.getcenter().x + window->getSize().x * 0.25, window->getSize().y / 2));
	}
	

}

void Gamestate::KeybindShuriken()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V) and !throwshuriken)
	{
		shurikenbigs.push_back(Shuriken(shuriken_big, player1.getcenter(), aimdirectionnorm));
		throwshuriken = true;
		player1.row = 11;
		player1.dx = 0;
		player1.dy = 0;
		player1.enegyFlow -= 20;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V) and throwshuriken)
	{
		throwshuriken = false;
	}
}

void Gamestate::updateShuriken()
{
}

void Gamestate::manaManagement()
{
	if (player1.enegyFlow < 90)
		canUseSkill[0] = false;
	else if(player1.enegyFlow > 90 and !player1.sharingan)
		canUseSkill[0] = true;

	//Control slash
	if (player1.enegyFlow < 20 and player1.sharingan)
		canUseSkill[1] = false;
	else if(player1.enegyFlow > 20 and !slash and !player1.sharingan)
		canUseSkill[1] = true;

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
