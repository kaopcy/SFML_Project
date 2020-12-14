#include "Background_move.h"
Background_move::Background_move(sf::Texture &texture)
{
    this->backgroundmove.setTexture(btexture);
    this->inversetexture = btexture;

    this->inversetexture2.loadFromFile("Background/Background_invert3.jpg");
    this->Tslash.loadFromFile("splash/slasheffect.png");
    this->sFireBackgroundk.setTexture(FireBackground);
    this->Tslash.setSmooth(true);
    this->slasheffect.setTexture(this->Tslash);
    this->slasheffect.setOrigin(this->Tslash.getSize().x / 2, this->Tslash.getSize().y / 2);
    this->slasheffect.setScale(this->slashscale, this->slashscale);
    this->slasheffect2.setTexture(this->Tslash);
    this->slasheffect2.setOrigin(this->Tslash.getSize().x / 2, this->Tslash.getSize().y / 2);
    this->slasheffect2.setScale(this->slashscale, this->slashscale);
    this->slasheffect2.setPosition(960, 540);
    this->slasheffect2.setColor(sf::Color::Red);
    this->stopbackgroundmove.setTexture(this->inversetexture2);
    this->stopbackgroundmove.setOrigin((this->inversetexture2.getSize().x / 4) / 2, this->inversetexture2.getSize().y / 2);
    this->stopbackgroundmove.setPosition(960, 540);

    this->stopbackgroundmove2.setTexture(btexture);
    this->stopbackgroundmove2.setColor(sf::Color::Red);

    this->ground.setTexture(groundTexture);
    this->ground.setOrigin(0, groundTexture.getSize().y);
    this->ground.setPosition(0, 1150);


}
Background_move::~Background_move()
{
}
void Background_move::draw(sf::RenderWindow& window, bool& sharingan, bool& slash)
{
    if (!sharingan)
    {
	    window.draw(this->backgroundmove);
    }
    else
    {
        if (!slash)
        {
                window.draw(this->stopbackgroundmove2);
        }
        else
        {
            window.draw(this->slasheffect);
        }
            

    }
    if (slash or sharingan)
    {
        if(slash)
        window.draw(this->slasheffect);
        if (sharingan)
        window.draw(this->slasheffect2);
    }
    window.draw(this->ground);

}
void Background_move::background_update(float deltatime , bool &sharingan, bool& slash , const sf::Vector2f playerposi)
{
    if (slash or sharingan)
    {
        this->slasheffect.setPosition(playerposi);
        this->slasheffect.setScale(this->slashscale, this->slashscale);
        this->slasheffect2.setScale(this->slashscale, this->slashscale);

    }
    else
    {
        this->slashscale = 2;
    }
    this->slashscale += 1;
    this->backgroundmove.setTextureRect(sf::IntRect((int)i, 0, 3000, 1080));
    this->ground.setTextureRect(sf::IntRect((int)j, 0, 3000, 1080));
    if (slash)
    {
        this->backgroundmove.setColor(sf::Color::Red);
    }
    else
    {
        this->backgroundmove.setColor(sf::Color::White);
    }

    if (sharingan)
    {
        this->stopbackgroundmove.setScale(backgroundscale, backgroundscale);
        this->backgroundscale += 0.1;
        if (this->backgroundscale >= 1)
        {
            this->backgroundscale = 1;
        }
        this->inversetime += deltatime;
        if (this->inversetime >= 0.75 and this->inverseflag)
        {
            this->inverseflag = false;
        }


    }
    else
    {
        this->backgroundscale = 0;
        this->inverseflag = true;
        this->inversetime = 0;
    }


    this->totaltime += deltatime;
    if (this->totaltime >= .01f)
    {
        this->totaltime -= .01f;
        this->i += 2;
        j += 2;
    }
    
    if (this->i > 6000)
    {
        this->i = 0;
    }
    if (this->j > 3000)
    {
        this->j = 0;
    }
}