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
	sf::Vector2u imageCount; //รูปเราคือ 3*3 
	sf::Vector2u currentImage; // current image ก็เหมือน animation frame ของเรา 
	float offsetanimation;
	float switchTime;

};

class Animation
{
};


