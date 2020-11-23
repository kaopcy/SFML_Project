#include "player.h"

Player::Player(int playertex ,sf::Vector2u imageframe, float speed):
	animationframe(0) , dx(0) , dy(0)  , onground(0) , direction(0,0)
{
	texturecontrol(playertex);
	hpbar.setFillColor(sf::Color(67,219,29));
	hpbar.setOrigin(sf::Vector2f(0, hpbar.getSize().y));
	hpbar.setPosition(sf::Vector2f(100, 20));
	hpbar.setScale(0.7, 0.7);
	this->hptexture.setTexture(&thp);
	hptexture.setPosition(sf::Vector2f(hpbar.getPosition().x - 50, hpbar.getPosition().y - hpbar.getSize().y - 5) );
	hptexture.setOrigin(sf::Vector2f(0, 0));
	hptexture.setSize(sf::Vector2f(thp.getSize().x , thp.getSize().y));
	hptexture.setScale(0.7, 0.7);

	this->player.setTexture(tplayer);
	this->imageframe = imageframe;
	this->testspeed = speed;
	this->player.setScale(0.4, 0.4);
	this->currentframe.x = (tplayer.getSize().x / imageframe.x) * player.getScale().x;
	this->currentframe.y = (tplayer.getSize().y / imageframe.y) * player.getScale().x;
	this->frame.x = (tplayer.getSize().x / imageframe.x);
	this->frame.y = (tplayer.getSize().y / imageframe.y);
	//player clone
	player_clone.left = 400.0f;
	player_clone.top = 800.0f;
	player_clone.width  = currentframe.x;
	player_clone.height = currentframe.y;
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(1);
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setSize(sf::Vector2f(player_clone.width, player_clone.height));

	arm.setSize(sf::Vector2f(100.0, 500.0));
	arm.setOutlineColor(sf::Color::Red);
	arm.setOutlineThickness(1);
	arm.setOrigin(sf::Vector2f(arm.getSize().x / 2, arm.getSize().y));
	arm.setFillColor(sf::Color::Transparent);
	circle.setRadius(11);
	circle.setFillColor(sf::Color::Red);
}

Player::~Player()
{

}

void Player::update(const float delta_player  , const float degree)
{
	armDisable(getWeapon(), degree);
	hpbar.setSize(sf::Vector2f(hp * 100, 70));

	this->hitbox.setPosition(sf::Vector2f(player_clone.left, player_clone.top));
	this->delta_player = delta_player;
	this->velocity.x = (int)dx * delta_player * speed;
	this->velocity.y = (int)dy * delta_player * 99.8;
	this->player.setPosition(player_clone.left,player_clone.top);
	this->player.setTextureRect(sf::IntRect (frame.x * animationframe , row  * frame.y , frame.x ,frame.y));
	offsetanimation += delta_player;
	if (offsetanimation >= switchtime)
	{
		offsetanimation -= switchtime;
		animationframe++;
	}
	if (animationframe >= imageframe.x)
	{
		animationframe = 0;
	}

}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(player);
	window.draw(hitbox);
	if (getWeapon() == 1)
	{
		window.draw(arm);

	}
	//window.draw(circle);
	window.draw(hpbar);
	window.draw(hptexture);
}

void Player::moveplayer()
{
	player_clone.left += velocity.x;
	offsetadd += delta_player;
	if (offsetadd >= 0.15)
	{
		offsetadd -= 0.15;
	}
		player_clone.top += velocity.y;
	dx = 0;
	if (!onground)
	{
		dy += 2;
	}

	
}

void Player::texturecontrol(int playertex)
{
	if (playertex == 1)
	{
		tplayer.loadFromFile("Player/Player.png");
		thp.loadFromFile("hpbar/hpbar.png");
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


