#include "collision_test.h"

collision_test::collision_test()
{
}

collision_test::~collision_test()
{
}

bool collision_test::iscollision(sf::FloatRect globalinbound1, sf::FloatRect globalinbound2)
{
	if (globalinbound1.intersects(globalinbound2))
	{
		std::cout << "fucking hit eiei" << std::endl;
		return(true);
	}
	return(false);
}

