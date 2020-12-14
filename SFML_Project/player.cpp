#include "player.h"

Player::Player(int playertex ,sf::Vector2u imageframe, float speed):
	animationframe(0) , dx(0) , dy(0)  , onground(0) , direction(0,0)
{
	this->texturecontrol(playertex);
	this->hpbar.setFillColor(sf::Color(67,219,29));
	this->hpbar.setOrigin(sf::Vector2f(0, hpbar.getSize().y));
	this->hpbar.setPosition(sf::Vector2f(100, 20));
	this->hpbar.setScale(0.7, 0.7);
	this->hptexture.setTexture(&thp);
	this->hptexture.setPosition(sf::Vector2f(hpbar.getPosition().x - 50, hpbar.getPosition().y - hpbar.getSize().y - 5) );
	this->hptexture.setOrigin(sf::Vector2f(0, 0));
	this->hptexture.setSize(sf::Vector2f(thp.getSize().x , thp.getSize().y));
	this->hptexture.setScale(0.7, 0.7);

	this->player.setTexture(tplayer);
	this->imageframe = imageframe;
	this->testspeed = speed;
	this->player.setScale(0.2, 0.2);
	this->currentframe.x = (tplayer.getSize().x / imageframe.x) * player.getScale().x;
	this->currentframe.y = (tplayer.getSize().y / imageframe.y) * player.getScale().x;
	this->frame.x = (tplayer.getSize().x / imageframe.x);
	this->frame.y = (tplayer.getSize().y / imageframe.y);
	//player clone
	this->player_clone.left = 1500;
	this->player_clone.top = 0.f;
	this->player_clone.width  = currentframe.x ;
	this->player_clone.height = currentframe.y ;

	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineThickness(1);
	this->hitbox.setOutlineColor(sf::Color::Red);
	this->hitbox.setSize(sf::Vector2f(player_clone.width, player_clone.height));

	this->arm.setSize(sf::Vector2f(100.0, 500.0));
	this->arm.setOutlineColor(sf::Color::Red);
	this->arm.setOutlineThickness(1);
	this->arm.setOrigin(sf::Vector2f(arm.getSize().x / 2, arm.getSize().y));
	this->arm.setFillColor(sf::Color::Transparent);
	this->circle.setRadius(11);
	this->circle.setFillColor(sf::Color::Red);

	this->sEnegy.setTexture(tEnegy);
	this->sEnegy.setScale(0.7, 0.7);
	
		this->enegy.setFillColor(sf::Color(31, 255, 234));
	this->enegybarSize.x = sEnegy.getGlobalBounds().width * 0.932;
	this->enegybarSize.y = sEnegy.getGlobalBounds().height * 0.382;

	this->sHP.setTexture(tHP);
	this->sHP.setScale(0.7, 0.7);
	this->HP.setFillColor(sf::Color(255, 57, 57));
	this->hpBarSize.x = sHP.getGlobalBounds().width * 0.932;
	this->hpBarSize.y = sHP.getGlobalBounds().height * 0.382;

	this->tShield.loadFromFile("shield/shield.png");
	this->sShield.setTextureRect(sf::IntRect((this->tShield.getSize().x / 6) * animationframe, this->tShield.getSize().y / 3 * 0, this->tShield.getSize().x / 6, this->tShield.getSize().y / 3));

	this->flame.setTextureRect(sf::IntRect((this->tShield.getSize().x / 6) * animationframe, this->tShield.getSize().y / 3 * 2, this->tShield.getSize().x / 6, this->tShield.getSize().y / 3));
	this->flame.setTexture(tShield);
	this->flame.setScale(0.5, 0.5);
	this->flame.setOrigin(this->tShield.getSize().x / 12, (this->tShield.getSize().y / 3) * 0.65);

	this->sShield.setTexture(tShield);
	this->sShield.setScale(0.5, 0.5);
	this->sShield.setOrigin(this->tShield.getSize().x / 12, (this->tShield.getSize().y / 3) * 0.65);
	

	for (size_t i = 0; i <= 9; i++)
	{
		resetanimation[i] = false;
	}
}

Player::~Player()
{

}

void Player::update(const float delta_player  , const float degree , bool &ultimate , const sf::Vector2f& view)
{
	this->sHP.setPosition(sf::Vector2f(view.x +10 , 5));
	this->HP.setPosition(this->sHP.getPosition().x + (sHP.getGlobalBounds().width * 0.03465), this->sHP.getPosition().y + (sHP.getGlobalBounds().height * 0.125));
	this->sEnegy.setPosition(sf::Vector2f(view.x + 960, 5));
	this->enegy.setPosition(this->sEnegy.getPosition().x + (sEnegy.getGlobalBounds().width * 0.03465), this->sEnegy.getPosition().y + (sEnegy.getGlobalBounds().height * 0.125));

	if (ultimate)
	{
		player_clone.width + 200;
		player_clone.height + 200;
	}
	armDisable(getWeapon(), degree);
	hpbar.setSize(sf::Vector2f(hp * 100, 70));

	this->hitbox.setPosition(this->getcenter());
	this->delta_player = delta_player;
	this->velocity.x = (int)dx * delta_player * speed;
	this->velocity.y = (int)dy * delta_player * 99;
	this->player.setPosition(player_clone.left,player_clone.top);
	this->player.setTextureRect(sf::IntRect (frame.x * animationframe , row  * frame.y , frame.x ,frame.y));

	this->enegy.setSize(sf::Vector2f(enegybarSize.x * this->enegyRatio , enegybarSize.y ));
	this->enegyRatio = this->enegyFlow / enegyMax;

	this->HP.setSize(sf::Vector2f(hpBarSize.x * this->hpRatio, hpBarSize.y));
	this->hpRatio = this->hpFlow / hpMax;
	if(enegyFlow <= enegyMax)
	enegyFlow += 0.125;

	if (isShield)
	{
		
		if(faceRight)
		this->sShield.setTextureRect(sf::IntRect((this->tShield.getSize().x / 6) * animationframe, this->tShield.getSize().y / 3 * 0, this->tShield.getSize().x / 6, this->tShield.getSize().y / 3));
		else
		this->sShield.setTextureRect(sf::IntRect((this->tShield.getSize().x / 6) * animationframe, this->tShield.getSize().y / 3 * 1, this->tShield.getSize().x / 6, this->tShield.getSize().y / 3));

		this->flame.setTextureRect(sf::IntRect((this->tShield.getSize().x / 6) * animationframe1, this->tShield.getSize().y / 3 * 2, this->tShield.getSize().x / 6, this->tShield.getSize().y / 3));
		sShield.setPosition(this->getcenter());
		flame.setPosition(this->getcenter());

		this->hitbox.setSize(sf::Vector2f(this->sShield.getGlobalBounds().width, this->sShield.getGlobalBounds().height));
		this->hitbox.setOrigin(this->hitbox.getSize().x / 2, this->hitbox.getSize().y / 2);

	}
	else
	{
		this->hitbox.setSize(sf::Vector2f(this->player.getGlobalBounds().width / 2, this->player.getGlobalBounds().height));
		this->hitbox.setOrigin(this->hitbox.getSize().x / 2, this->hitbox.getSize().y / 2);

	}

	offsetanimation += delta_player;
	if (offsetanimation >= switchtime)
	{
		offsetanimation -= switchtime;
		animationframe++;
		animationframe1++;
	}
	if (row == 11 and !resetanimation[0])
	{
		animationframe = 0;
		resetanimation[0] = true;
	}
	if (row == 11)
	{
		if (animationframe >= imageframe.x)
		{
			animationframe = 5;
		}
	}
	
	if (row == 12 and !resetanimation[1])
	{
		animationframe = 0;
		animationframe1 = 0;

		resetanimation[1] = true;
	}
	if (row == 12)
	{
		if (animationframe >= imageframe.x)
		{
			animationframe = 5;
		}
		if (animationframe1 >= imageframe.x)
			animationframe1 = 0;
	}

	if (row != 11 and row != 12)
	{
		resetanimation[0] = false;
		resetanimation[1] = false;

		if (animationframe >= imageframe.x)
		{
			animationframe = 0;
		}
	}

}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(this->player);
	if (getWeapon() == 1)
	{
		window.draw(this->arm);

	}
	//window.draw(circle);
	/*window.draw(this->hpbar);
	window.draw(this->hptexture);*/
	window.draw(this->enegy);
	window.draw(this->sEnegy);
	window.draw(this->HP);
	window.draw(this->sHP);
	if (isShield)
	{
		window.draw(this->sShield);
		window.draw(this->flame);
	}
	window.draw(this->hitbox);
}

void Player::moveplayer()
{
	player_clone.left += velocity.x;
	player_clone.top  += velocity.y;
	if (!onground)
	{
		if (sharingan)
			dy += 0.25;
		else
			dy += 1;
	}
	else
		dy = 0;

	
}

void Player::texturecontrol(int playertex)
{
	if (playertex == 1)
	{
		if(!tplayer.loadFromFile("Player/Player.png"))
		tplayer.loadFromFile("Player/Player.png");
		tEnegy.loadFromFile("hpbar/enegybar.png");
		tHP.loadFromFile("hpbar/enegybar.png");

		tplayer.setSmooth(true);
		thp.setSmooth(true);
		tHP.setSmooth(true);

		tEnegy.setSmooth(true);
	}
	
}

void Player::armDisable(short int getweapon , const float degree)
{
	if (getweapon == 1)
	{
		arm.setPosition(getcenter());
		arm.setRotation(degree + 90);
	}
}


