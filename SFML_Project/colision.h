#pragma once
#include<SFML/Graphics.hpp>
class colision
{
public:
	colision();
	~colision();
	bool iscollion(sf::RectangleShape &thing1 , sf::RectangleShape &thing2)
	{
		
		sf::Vector2f t1_halfsize(thing1.getSize().x / 2, thing1.getSize().y / 2);
		sf::Vector2f t1_position(thing1.getPosition().x + t1_halfsize.x, thing1.getPosition().y + t1_halfsize.y);

		sf::Vector2f t2_halfsize(thing2.getSize().x / 2, thing2.getSize().y / 2);
		sf::Vector2f t2_position(thing2.getPosition().x + t2_halfsize.x, thing2.getPosition().y + t2_halfsize.y);

		float deltaX = t1_position.x - t2_position.x;
		float deltaY = t1_position.y - t2_position.y;
		float intersectX = abs(deltaX) - (t1_halfsize.x + t2_halfsize.x);
		float intersectY = abs(deltaY) - (t1_halfsize.y + t2_halfsize.y);

		if (intersectX < 0.0f and intersectY < 0.0f)
		{
			float push = std::min(std::max(push, 0.0f), 1.0f);

			if (intersectX > intersectY)
			{
				if (deltaX > 0.0f)
				{
					thing2.move(intersectX * push, 0.0f);
				}
			}

			return true;
		}
		return false;
	}

private:
	sf::RectangleShape thing1;
	sf::RectangleShape thing2;

};

