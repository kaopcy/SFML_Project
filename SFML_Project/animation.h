#pragma once
#include<SFML\Graphics.hpp>
class animation
{
public:
	animation(sf::Texture texture, sf::Vector2u imageCount, float switchTime);
    virtual ~animation();
	void update(int row, float millis);

	
public:
	sf::IntRect playerRect;
private:
	sf::Vector2u imageCount; //�ٻ��Ҥ�� 3*3 
	sf::Vector2u currentImage; // current image ������͹ animation frame �ͧ��� 
	float offsetanimation;
	float switchTime;

};

class Animation
{
};


