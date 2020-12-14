#include "Boss.h"

Boss::Boss(sf::Vector2f firstPos):
	direct(0,0)
{
	this->shape.setPosition(firstPos);
	this->shape.setSize(sf::Vector2f(200,300));
	this->shape.setFillColor(sf::Color::Yellow);


	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineThickness(1);
	this->hitbox.setOutlineColor(sf::Color::Green);

	this->circle.setRadius(10);
	this->circle.setFillColor(sf::Color::Magenta);
	this->circle.setPosition(aimDirect());
	this->circle.setOrigin(this->circle.getRadius() , this->circle.getRadius());
	
	this->sHP.setTexture(tHP);
	this->sHP.setScale(0.25, 0.5);

	this->HPbarSize.x = sHP.getGlobalBounds().width * 0.932;
	this->HPbarSize.y = sHP.getGlobalBounds().height * 0.382;

	this->HP.setFillColor(sf::Color(37, 228, 94));
}

Boss::~Boss()
{
}

void Boss::draw(sf::RenderWindow& window)
{
	window.draw(this->shape);
	window.draw(this->hitbox);
	window.draw(this->circle);
	window.draw(this->sHP);
	window.draw(this->HP);
}

void Boss::update(const float& deltatime , const float& ground , const sf::Vector2f &playerPosition)
{
	this->hitbox.setPosition(this->shape.getPosition());
	this->hitbox.setSize(this->shape.getSize());
	this->circle.setPosition(aimDirect());

	this->deltaX = shape.getPosition().x - playerPosition.x;
	this->deltaY = shape.getPosition().y - playerPosition.y;

	this->bossjump(deltatime, ground);
	this->BossTimer += deltatime;
	this->degreecalculate(playerPosition);
	this->bossSkill();
	this->HPManagement();
	this->knockbackSkill(playerPosition , deltatime);

	if (deltaX > 0 and !knockback)
	{
		direct.x = -1;
		Movespeed = 100;
	}
	if (deltaX < 0 and !knockback)
	{
		direct.x = 1;
		Movespeed = 100;
	}

	this->shape.move( this->direct.x * deltatime * Movespeed, this->direct.y * deltatime * 15);
}

void Boss::bossjump(const float& deltatime, const float& ground)
{
	if (!this->onground)
	{
		this->direct.y += 2;
	}
	if (this->getbot() > ground)
	{
		this->shape.setPosition(sf::Vector2f(this->shape.getPosition().x, ground - this->shape.getSize().y));
		this->onground = true;
		this->direct.y = 0;
	}
	if ((int)this->BossTimer % 7 == 0 and onground)
	{
		this->onground = false;
		this->direct.y = -100;
	}
}

void Boss::degreecalculate(const sf::Vector2f& playerPosition)
{
	this->degree = atan2(playerPosition.y - this->aimDirect().y, playerPosition.x - this->aimDirect().x) * (180 / 3.141);
	this->aimdirection = playerPosition - this->aimDirect();
	this->aimdirectionnorm = this->aimdirection / sqrt(pow(this->aimdirection.x, 2) + (pow(this->aimdirection.y, 2)));
}

void Boss::bossSkill()
{
	//control timer
	if (((int)this->BossTimer % 8 == 0 or (int)this->BossTimer % 8 == 1))
	{
		rapidSkill = true;
	}
	else { rapidSkill = false; }

	if (((int)this->BossTimer % 15 == 0 or (int)this->BossTimer % 15 == 1))
	{
		healSkill = true;
	}
	else { healSkill = false; }

	//control skill
	if (rapidSkill)
	{
		this->BulletReload = 5;
		this->bulletSpeed = 30;
		this->shape.setFillColor(sf::Color::Red);
	}
	else
	{
		this->BulletReload = 20;
		this->bulletSpeed = 10;
	}
	//Control colours
	if (healSkill)
	{
		this->shape.setFillColor(sf::Color::Blue);
	}
	else if (rapidSkill)
	{
		this->shape.setFillColor(sf::Color::Red);
	}
	else
	{
		this->shape.setFillColor(sf::Color::Yellow);
	}
}

void Boss::HPManagement()
{
	this->sHP.setPosition(this->shape.getPosition().x , this->shape.getPosition().y - (this->sHP.getGlobalBounds().height));
	this->HP.setPosition(this->sHP.getPosition().x + (sHP.getGlobalBounds().width * 0.03465), this->sHP.getPosition().y + (sHP.getGlobalBounds().height * 0.125));
	this->HP.setSize(sf::Vector2f(this->HPbarSize.x * this->HPratio, this->HPbarSize.y));
	this->HPratio = this->hpFlow / hpMax;
	if (hpFlow > hpMax)
	{
		hpFlow = hpMax;
	}
}

void Boss::knockbackSkill(const sf::Vector2f& playerPosition, const float& deltatime)
{
	if (knockback)
	{
		if (playerPosition.x < getleft())
		{
			direct.x = 1;
			if (!setMovespeedKnockback)
			{
				Movespeed = 700;
				setMovespeedKnockback = true;
			}
			if (Movespeed <= 0)
			{
				Movespeed = 0;
			}
		}
		if (playerPosition.x > getright())
		{
			direct.x = -1;
			if (!setMovespeedKnockback)
			{
				Movespeed = 700;
				setMovespeedKnockback = true;
			}
			if (Movespeed <= 0)
			{
				Movespeed = 0;
			}
		}
		knockbackTimer -= deltatime;
		Movespeed -= 20;
		if (knockbackTimer <= 0)
		{
			knockbackTimer = 1;
			knockback = false;
			setMovespeedKnockback = false;
		}
	}
}

