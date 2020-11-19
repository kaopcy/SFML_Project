#include "Enemy.h"
Enemy::Enemy(int texturenum, int hp, sf::Vector2u imageframe) :
	hpmax(hp)
{
	this->texturecontrol(texturenum);
	this->hp = hp;
	this->currentframeexplode.x = Texplode.getSize().x / 8;
	this->currentframeexplode.y = Texplode.getSize().y;
	this->hpRec.setFillColor(sf::Color(255, 40, 24));
	explosion.setTexture(Texplode);
	explosion.setPosition(-4000, -4000);
	explosion.setScale(1.5, 1.5);
	S_enemy.setTexture(Etexture);
	this->imageframe = imageframe;
	currentframe.x = Etexture.getSize().x / imageframe.x;//ค่าคือความยาวรูปทั้งหมดหาร 3 (น่าจะเป็นค่าคงที่)
	currentframe.y = Etexture.getSize().y / imageframe.y;//ค่าคือความกว้างรูปทั้งหมดหาร 3 (น่าจะเป็นค่าคงที่)
	animationframe = 0;
	this->hitbox.setSize(sf::Vector2f(currentframe));
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineThickness(1);
	this->hitbox.setOutlineColor(sf::Color::Red);
}

Enemy::~Enemy()
{
}

void Enemy::update(const float deltatime)
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
			dy += 2;
		}
		hitbox.move(dx * deltatime * (rand() % (200 - 100) + 100), dy);
	}

	if (dead)
	{
		
		explosion.setPosition(hitbox.getPosition());
		explosion.setTextureRect(sf::IntRect(currentframeexplode.x * animationexplode, 0, currentframeexplode.x, currentframeexplode.y));
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
		lifetime -= deltatime;
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
		Texplode.loadFromFile("Explode/Explode.png");
		Etexture.loadFromFile("Enemy/Enemy2.png");
	}
}
