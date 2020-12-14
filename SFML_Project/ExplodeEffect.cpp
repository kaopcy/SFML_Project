#include "ExplodeEffect.h"

ExplodeEffect::ExplodeEffect(const sf::Vector2f &position ,short int type, const sf::Texture& texture):
	type(type)
{
	texturecontrol();
	this->currentFrame.x = texture.getSize().x / imageframeX;
	this->currentFrame.y = texture.getSize().y / imageframeY;

	shape.setTexture(texture);
	shape.setPosition(position);
	shape.setOrigin(texture.getSize().x / (2 * imageframeX), texture.getSize().y / (2 * imageframeY));
	

}

ExplodeEffect::~ExplodeEffect()
{
}

void ExplodeEffect::update(const float& deltatime)
{
	this->shape.setTextureRect(sf::IntRect(currentFrame.x * animationFrame, currentFrame.y * row, currentFrame.x, currentFrame.y));
	offsetAnimation += deltatime;
	if (offsetAnimation >= offsetAnimationSpeed)
	{
		offsetAnimation -= offsetAnimationSpeed;
		animationFrame++;
	}
	if (animationFrame >= imageframeX)
	{
		lifeTime = true;
	}
}

void ExplodeEffect::draw(sf::RenderWindow& window)
{
	window.draw(this->shape);
}

void ExplodeEffect::texturecontrol()
{
	if(type == 1)
	{
		this ->imageframeX = 8;
		this ->imageframeY = 2;
		this->shape.setScale(3, 3);
		this->offsetAnimationSpeed = 0.1;
	}
}
