#include "Assetmanager.h"

Assetmanager::Assetmanager()
{
}

Assetmanager::~Assetmanager()
{
}

void Assetmanager::Loadtexture(string name, string filename)
{
    sf::Texture tex;
    if (tex.loadFromFile(filename))
    {
        this->_textures[name] = tex;
    }

}

sf::Texture& Assetmanager::gettexture(string name)
{
    return this->_textures.at(name);
}

void Assetmanager::Loadfont(string name, string filename)
{
    sf::Font font;
    if (font.loadFromFile(filename))
    {
        this->_fonts[name] = font;
    }
}

sf::Font& Assetmanager::getfont(string name)
{
    return this->_fonts.at(name);
}

void Assetmanager::Loadfile()
{
    
}
