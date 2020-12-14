#pragma once
#include<SFML/Graphics.hpp>
extern sf::Texture btexture;
extern sf::Texture groundTexture;
extern sf::Texture FireBackground;
class Background_move
{

public:

	Background_move(sf::Texture &texture);
	virtual ~Background_move();
	sf::Sprite backgroundmove;
	sf::Sprite slasheffect;
	sf::Sprite slasheffect2;
	sf::Sprite ground;
	void draw(sf::RenderWindow& window, bool& sharingan, bool& slash);
	void background_update(float deltatime , bool &sharingan ,  bool& slash, const sf::Vector2f playerposi);
	float getGround() { return this->ground.getPosition().y - 150; }
private:

	sf::Texture Tslash;
	sf::Texture inversetexture2;
	sf::Texture inversetexture;
	sf::Sprite stopbackgroundmove;
	sf::Sprite stopbackgroundmove2;
	sf::Sprite sFireBackgroundk;
	float backgroundscale = 0;
	float slashscale = 2;
	int i=0;
	int j = 0;
	float totaltime=0;
	float inversetime = 0;
	float invertscale = 1;
	bool inverseflag = true;
};

