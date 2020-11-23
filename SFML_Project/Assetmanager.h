#pragma once
#include "State.h"
#include <map>
#include <vector>
class Assetmanager
{
public:
	Assetmanager();
	~Assetmanager();
	void Loadtexture(string name, string filename);
	sf::Texture& gettexture(string name);
	void Loadfont(string name, string filename);
	sf::Font& getfont(string name);
	
	void Loadfile();

private:
	map<string, Texture> _textures;
	map<string, Font> _fonts;

};

