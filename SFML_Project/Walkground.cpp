#include "Walkground.h"
using namespace sf;
Walkground::Walkground(float speed , sf::Vector2f size , sf::Vector2f position)
{
	body.setSize(size);
	ground = 0;
	delta = 0;
	this->speed = speed;
	body_clone = FloatRect( position.x , position.y,size.x,size.y);
	body.setFillColor(sf::Color::Yellow);
}
void Walkground::update(float delta , float *ground)
{
	if (body_clone.left >= 1500 and dx ==1)
	{
		dx = -1;
		body_clone.top = rand() % (1000 - 0) + 0;
	}
	if (body_clone.left <= 0 and dx == -1)
	{
		dx = 1;
		body_clone.top = rand() % (1000 - 0) + 0;
	}
	//body_clone.left += speed * delta * dx ;
	this->ground = *ground;
	this->totaltime += delta * 10;
	this->delta = delta;
	body.setPosition(body_clone.left , body_clone.top);
}




