#pragma once
#include<SFML\Graphics.hpp>
class animation
{
public:
	animation(sf::Texture texture, sf::Vector2u imageCount, float switchTime);
	~animation();
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

/*millis = elapsed.asMilliseconds();
void move_player()
{
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) and player.getPosition().x>0)
        {
            player.move(-2, 0);
            player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 2, 300, 200));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) and player.getPosition().x<1680)
        {

            player.move(2, 0);
            player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 1, 300, 200));

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) { window.close(); }

       /* if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) and !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) and !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) and !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 0, 300, 200));
        }*/
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) and !freefall)
        {
            jumpstate = true;
        }
        /*animationFrame++;
        if (animationFrame >= 2) { animationFrame = 0; }


}*/
/*void jump()
{
    if (jumpstate)
    {
        player.move(0, -(gravity * 1.2));
        gravity -= 0.2;

        if (player.getPosition().y <= ground - 325 or player.getPosition().y >= ground)
        {
            jumpstate = false;
            freefall = true;
            gravity = 0;
        }
    }
    if (!jumpstate and freefall)
    {
        player.move(0, +gravity * 1.5);
        gravity += 0.3;
        if (player.getPosition().y >= ground)
        {
            freefall = false;
            gravity = 12;
        }
    }
}*/

