#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <sstream>  
#include <string.h>
#include <stack>
#include <map>

#include "player.h"
#include "Background_move.h"
#include "Text.h"
#include "Bullet.h"
#include "Platform.h"
#include "Enemy.h"
#include <vector>

class State
{
public:
	State(sf::RenderWindow *window);
	virtual ~State();
	virtual void updatekeybind(const float &deltatime) = 0;
	virtual void endstate() = 0;
	virtual void checkforquit(); 
	virtual void update(const float &deltatime) = 0;
	virtual void render(sf::RenderTarget *target = nullptr) = 0;
	const bool& getquit() const;

private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit = false;
};

