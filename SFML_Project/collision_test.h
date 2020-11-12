#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
class collision_test
{
public:
	collision_test();
	~collision_test();
	bool iscollision(sf::FloatRect globalinbound1, sf::FloatRect globalinbound2);
	
private:
	sf::FloatRect globalinbound1;
};

