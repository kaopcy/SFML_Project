#include "animation.h"
animation::animation(sf::Texture texture, sf::Vector2u imageCount, float switchTime) // image count 㹷������ 3*3
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	offsetanimation = 0.0f;
	playerRect.width = texture.getSize().x / imageCount.x; // image count ��ҡ�˹��ͧ��� 3*3
	playerRect.height = texture.getSize().y / imageCount.y;
}

animation::~animation()
{
}
void animation::update(int row, float millis)
{
	currentImage.y = row;
	if (millis - offsetanimation > switchTime)
	{
		offsetanimation = millis;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	playerRect.top = currentImage.y * playerRect.height;
	playerRect.left = currentImage.x * playerRect.width;
}