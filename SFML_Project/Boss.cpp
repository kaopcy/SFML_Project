#include "Boss.h"

Boss::Boss():
	direct(0,0)
{
	this->shape.setPosition(1000, 0);
	this->shape.setSize(sf::Vector2f(300, 600));
	this->shape.setFillColor(sf::Color::Yellow);


	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineThickness(1);
	this->hitbox.setOutlineColor(sf::Color::Green);

	this->circle.setRadius(10);
	this->circle.setFillColor(sf::Color::Magenta);
	this->circle.setPosition(aimDirect());
	this->circle.setOrigin(this->circle.getRadius() , this->circle.getRadius());
}

Boss::~Boss()
{
}

void Boss::draw(sf::RenderWindow& window)
{
	window.draw(this->shape);
	window.draw(this->hitbox);
	window.draw(this->circle);
}

void Boss::update(const float& deltatime , const float& ground , const sf::Vector2f &playerPosition)
{
	this->deltaX = shape.getPosition().x - playerPosition.x;
	this->deltaY = shape.getPosition().y - playerPosition.y;
	this->hitbox.setPosition(this->shape.getPosition());
	this->hitbox.setSize(this->shape.getSize());
	this->bossjump(deltatime, ground);
	this->timetojump += deltatime;
	this->circle.setPosition(aimDirect());
	this->degreecalculate(playerPosition);
	if (deltaX > 0)
		direct.x = -1;
	if (deltaX < 0)
		direct.x = 1;

	this->shape.move( this->direct.x * deltatime * 100, this->direct.y * deltatime * 15);
}

void Boss::bossjump(const float& deltatime, const float& ground)
{
	if (!this->onground)
	{
		this->direct.y += 4;
	}
	if (this->getbot() > ground)
	{
		this->shape.setPosition(sf::Vector2f(this->shape.getPosition().x, ground - this->shape.getSize().y));
		this->onground = true;
		this->direct.y = 0;
	}
	if ((int)this->timetojump % 7 == 0)
	{
		this->onground = false;
		this->direct.y = -70;
	}
}

void Boss::degreecalculate(const sf::Vector2f& playerPosition)
{
	//degree = atan2(mouseposition.y - player1.getcenter().y, mouseposition.x - player1.getcenter().x) * (180 / 3.141);
	aimdirection = playerPosition - aimDirect();
	aimdirectionnorm = aimdirection / sqrt(pow(aimdirection.x, 2) + (pow(aimdirection.y, 2)));
}

