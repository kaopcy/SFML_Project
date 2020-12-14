#pragma once
#include <SFML/Graphics.hpp>
class Bullet
{
public:

	Bullet(sf::Texture &texture ,float speed ,const int type );
	virtual ~Bullet();
	float reload = 5.0f;
	float speed;
	sf::RectangleShape shape;
	sf::Vector2f currentvelocity;
	void update(const float& deltatime, bool& sharingan);
	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape hitbox; 
	sf::Texture tParticle;
	sf::Sprite sParticle;
	float spinspeed = 0;
	short int type;
};

