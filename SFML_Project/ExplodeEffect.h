#pragma once
#include "Defination.h"
class ExplodeEffect
{
public:
	ExplodeEffect(const sf::Vector2f &position ,short int type, const sf::Texture &texture);
	virtual ~ExplodeEffect();
	void update(const float& deltatime);
	void draw(sf::RenderWindow& window);
	bool lifeTime = false;

private:
	sf::Sprite shape;
	sf::Vector2f currentFrame;
	short int imageframeX = 0;
	short int imageframeY = 0;
	short int type = 0;
	short int animationFrame = 0;
	short int row = 0;
	float offsetAnimation = 0;
	void texturecontrol();
	float offsetAnimationSpeed = 0.1;
};

