#include "Enemy.h"
Enemy::Enemy(sf::Texture &texture2 ,sf::Texture &texture ,int texturenum, int hp, sf::Vector2u imageframe , const sf::Vector2f &firstPosition) :
	hpmax(hp)
{

	this->S_enemy.setTexture(texture);
	this->explosion.setTexture(texture2);
	this->explosion.setPosition(-4000, -4000);
	this->explosion.setOrigin(sf::Vector2f(this->explosion.getGlobalBounds().width / 16, this->explosion.getGlobalBounds().height / 4));
	this->explosion.setScale(3,3);
	this->imageframe = imageframe;
	this->animationframe = 0;
	this->hp = hp;
	this->currentframeexplode.x = texture2.getSize().x / 8;
	this->currentframeexplode.y = texture2.getSize().y / 2;
	
	this->hpRec.setFillColor(sf::Color(255, 40, 24));
	this->currentframe.x = texture.getSize().x / imageframe.x;//ค่าคือความยาวรูปทั้งหมดหาร 3 (น่าจะเป็นค่าคงที่)
	this->currentframe.y = texture.getSize().y / imageframe.y;//ค่าคือความกว้างรูปทั้งหมดหาร 3 (น่าจะเป็นค่าคงที่)

	this->hitbox.setSize(sf::Vector2f(currentframe));
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineThickness(1);
	this->hitbox.setOutlineColor(sf::Color::Red);
	this->hitbox.setScale(0.6,0.6);
	this->hitbox.setPosition(firstPosition);
	this->S_enemy.setScale(hitbox.getScale());

	if (!Deadsoundbuffer.loadFromFile("Sound/Deadeffect_sound.wav"))
	{
		this->Deadsoundbuffer.loadFromFile("Sound/Deadeffect_sound.wav");
	}
	this->Deadeffect.setBuffer(this->Deadsoundbuffer);
	this->Deadeffect.setVolume(10);
}

Enemy::~Enemy()
{
	
}

void Enemy::update(const float deltatime , bool &slash , const float &ground )
{
	if (!dead)
	{
		this->hpRec.setSize(sf::Vector2f((hitbox.getSize().x * hp) / hpmax, 10));
		this->hpRec.setPosition(sf::Vector2f(hitbox.getPosition().x, hitbox.getPosition().y + hitbox.getSize().y + 5));

		this->S_enemy.setPosition(hitbox.getPosition());
		this->deltatime = deltatime;
		this->S_enemy.setTextureRect(sf::IntRect(currentframe.x * animationframe, currentframe.y * row, currentframe.x, currentframe.y));

		//Edit speed animation meteor
		offsetanimation += deltatime;
		if (offsetanimation >= 0.05f)
		{
			offsetanimation -= 0.05f;
			animationframe++;
			if (animationframe >= imageframe.x) { animationframe = 0; }
		}

		//Edit speed meteor
		offsetenemyspeed += deltatime;
		if (offsetenemyspeed >= 0.5f)
		{
			offsetenemyspeed -= 0.5f;
		}
	}

	if (!changePhases)
	{
		if (dx == 1)
		{
			row = 0;
		}
		else if (dx == -1)
		{
			row = 1;
		}
		if (!dead)
		{
			
			hitbox.move(dx * deltatime * (rand() % (200 - 100) + 100), dy);
		}
		if (S_enemy.getPosition().y+S_enemy.getGlobalBounds().height >= 1000)
		{
			changePhases = true;
		}
	}
	if (changePhases)
	{
		row = 0;
		dy = 0;
	}

	if (dead)
	{
		if (!slash)
		{
			//playDeadSound(dead);
			explosion.setPosition(getCenter());
			explosion.setTextureRect(sf::IntRect(currentframeexplode.x * animationexplode, currentframeexplode.y * 0, currentframeexplode.x, currentframeexplode.y));
			{
				//Edit speed animation explode
				offset2 += deltatime;
				if (offset2 >= 0.12)
				{
					offset2 -= 0.12;
					animationexplode++;
					if (animationexplode > 8) { erase = true; }
				}
			}
			lifetime -= deltatime;

		}
		if (slash)
		{
			if (lifetime >= lifetime / 2)
			{
				explosion.setPosition(getCenter());
				explosion.setTextureRect(sf::IntRect(currentframeexplode.x * animationexplode, currentframeexplode.y * 1, currentframeexplode.x, currentframeexplode.y));
				

			}
			else
			{
				explosion.setPosition(getCenter());
				explosion.setTextureRect(sf::IntRect(currentframeexplode.x * animationexplode, currentframeexplode.y * 0, currentframeexplode.x, currentframeexplode.y));
			}

			{
				//Edit speed animation explode
				offset2 += deltatime;
				if (offset2 >= 0.1)
				{
					offset2 -= 0.1;
					animationexplode++;
					if (animationexplode > 8) { animationexplode = 0; }
				}
			}
			lifetime -= (deltatime)*0.5;

		}
		
		
	}
}
void Enemy::draw(sf::RenderWindow& window)
{
	if (!dead)
	{
		window.draw(S_enemy);
		window.draw(hitbox);
		window.draw(hpRec);
	}
	

}

void Enemy::drawexplode(sf::RenderWindow& window)
{
	window.draw(explosion);
}

float Enemy::calculateHP( int hp , float sizeX)
{
	float percent = 100 / hp;
	float minus = (sizeX * percent) / 100;

	return minus;
}

void Enemy::texturecontrol(int num)
{
	if (num == 1)
	{
		
	}
}

void Enemy::playDeadSound(bool dead)
{
	if ((dead) and deadflag)
	{
		Deadeffect.play();
		deadflag = false;
	}
	else if (!dead)
	{
		deadflag = true;
	}
}

