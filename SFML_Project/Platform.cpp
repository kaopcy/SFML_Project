#include "Platform.h"

Platform::Platform(sf::Texture* texture , sf::Vector2f size, float speed , sf::Vector2f position)
{

	hitbox.setPosition(position);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(1);
	hitbox.setOutlineColor(sf::Color::Green);
	hitbox.setSize(size);

	body.setTexture(texture);
	//body.setOrigin(body.getSize());
}

Platform::~Platform()
{
}

void Platform::Update(float deltatime)
{
	body.setPosition(hitbox.getPosition().x, hitbox.getPosition().y);
}

void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(hitbox);
}
