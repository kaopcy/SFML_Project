#include <SFML/Graphics.hpp>
#include <iostream>
sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML_PROJECT", sf::Style::Close | sf::Style::Resize);
sf::Texture player_texture;
sf::Sprite player;
sf::Texture background_texture;
sf::Sprite background;
void move_player();
int animationFrame = 0;
int playerSizeX, backgroundSizeX;
int playerSizeY;
float i = 0;

int main()
{
    
    if (!player_texture.loadFromFile("player.png")) { printf("Error can't load player image \n"); }
    if (!background_texture.loadFromFile("background.jpg")) { printf("Error can't load player image \n"); }
    background.setTexture(background_texture);
    player.setTexture(player_texture);
    player.setTextureRect(sf::IntRect(0, 0, 300, 200));
    player.setPosition(750, 700);
    playerSizeX = player_texture.getSize().x / 3;
    playerSizeY = player_texture.getSize().y / 3;
    background.setPosition(0, 0);
    backgroundSizeX = background_texture.getSize().x / 3;
    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                std::cout  << "New window width "<< evnt.size.width << " New window height " << evnt.size.height << std::endl;
                
                break;
            case sf::Event::TextEntered:
                if (evnt.text.unicode < 128)
                {
                    printf("%c", evnt.text.unicode);
                    
                    
                }
                
            }
            if (evnt.type == evnt.Closed)
            {
                window.close();
            }
        }
        
        background.setTextureRect(sf::IntRect(i, 0, 1920, 1080));
        i+=2;
        if(i>3840)
        {
            i=0;
        }

        
        

        move_player();
        
        window.clear(sf::Color::Red);
        window.draw(background);
        window.draw(player);
        
        window.display();
    }
    
    return 0;
}

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) and player.getPosition().y>0)
        {
            player.move(0, -2);
            
           
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) and player.getPosition().y<700)
        {
            player.move(0, 2);
            
         
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) { window.close(); }

        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) and !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) and !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) and !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 0, 300, 200));
        }
        
        animationFrame++;
        if (animationFrame >= 2)
        {
            animationFrame = 0;
        }
       
        
}
