#include "stdafx.h"
#include "Cursor.h"

Cursor::Cursor()
{
    _texture.loadFromFile("cursor.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(0, 0);
    //_sprite.setPosition(0,500);
    //_sprite.setOrigin(_sprite.getGlobalBounds().width/, _sprite.getGlobalBounds().height);

}

void Cursor::setPosition(sf::Vector2f pos)
{
	_sprite.setPosition(pos);
}


void Cursor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
