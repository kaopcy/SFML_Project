#include "player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageframe, float speed):
	animationframe(0) , dx(0) , dy(0)  , onground(0) , direction(0,0)
{
	this->player.setTexture(*texture);
	this->imageframe = imageframe;
	this->testspeed = speed;
	this->player.setScale(5.0, 5.0);
	this->currentframe.x = (texture->getSize().x / imageframe.x) * player.getScale().x;
	this->currentframe.y = (texture->getSize().y / imageframe.y) * player.getScale().x;
	this->frame.x = (texture->getSize().x / imageframe.x);
	this->frame.y = (texture->getSize().y / imageframe.y);
	//player clone
	player_clone.left = 20.0f;
	player_clone.top = 20.0f;
	player_clone.width  = currentframe.x;
	player_clone.height = currentframe.y;
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(1);
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setSize(sf::Vector2f(player_clone.width, player_clone.height));

}

Player::~Player()
{

}

void Player::update(float delta_player, float ground, float degree)
{
	this->hitbox.setPosition(sf::Vector2f(player_clone.left, player_clone.top));
	this->delta_player = delta_player;
	this->velocity.x = (int)dx * delta_player * 1000;
	this->velocity.y = (int)dy * delta_player * 99.8;
	this->player.setPosition(player_clone.left,player_clone.top);
	this->degree = degree;
	this->player.setTextureRect(sf::IntRect (frame.x * animationframe , row  * frame.y , frame.x ,frame.y));
	offsetanimation += delta_player;
	if (offsetanimation >= switchtime)
	{
		offsetanimation -= switchtime;
		animationframe++;
	}
	if (animationframe >= imageframe.y)
	{
		animationframe = 0;
	}

}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(player);
	window.draw(hitbox);
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


