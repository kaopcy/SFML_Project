#pragma once



#include "Defination.h"


class State
{
public:
	State(sf::RenderWindow *window );
	virtual ~State();
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void updatekeybind(const float &deltatime , sf::Event& evnt) = 0;
	virtual void update(const float &deltatime , sf::Event& evnt) = 0;
	virtual void endstate() = 0;
	virtual void checkforquit(); 
	const bool& isEnd() const;
	const bool& getquit() const;
	const bool& getaddstate() const;

protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit = false;
	bool addstate = false;
	bool gameOver = false;

};

