#include "Enemy.h"
Enemy::Enemy(sf::Vector2u imageframe) 
{
	P_enemy.loadFromFile("player2.png");
	S_enemy.setTexture(P_enemy);
	S_enemy.setPosition(1900, 750);
	S_enemy.setOrigin(sf::Vector2f((P_enemy.getSize().x / (float)imageframe.x) / 2, (P_enemy.getSize().y / (float)imageframe.y) / 2));
	this->imageframe = imageframe;
	currentframe.x = P_enemy.getSize().x / imageframe.x;//ค่าคือความยาวรูปทั้งหมดหาร 3 (น่าจะเป็นค่าคงที่)
	currentframe.y = P_enemy.getSize().y / imageframe.y;//ค่าคือความกว้างรูปทั้งหมดหาร 3 (น่าจะเป็นค่าคงที่)
	animationframe = 0;
	row = 0;
}

Enemy::~Enemy()
{
}



void Enemy::update(float deltatime, float *ground)
{
	this->deltatime = deltatime;
	this->ground = *ground;
	S_enemy.setTextureRect(sf::IntRect(currentframe.x * animationframe, currentframe.y * row, currentframe.x, currentframe.y));
	offsetanimation += deltatime;
	if (offsetanimation >= 0.08f)
	{
		offsetanimation -= 0.08f;
		animationframe++;
		if (animationframe >= 9) { animationframe = 0; }
	}
}
void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(S_enemy);
}
void Enemy::enemy_update(sf::RenderWindow& window)
{
	sf::Vector2f movement(0.0f,0.0f);
	enemy_collision = S_enemy.getGlobalBounds();
	movement.x -= deltatime * 1000;
	draw(window);
	if (S_enemy.getPosition().x < 0)
	{
		S_enemy.setPosition(1900, ground);
	}
	S_enemy.move(movement);
}