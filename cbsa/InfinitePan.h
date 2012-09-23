#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class InfinitePan{
public:
	InfinitePan(void);
	~InfinitePan(void);
	void update(double deltaTime);
	sf::Sprite* setSprite(sf::Sprite*, float wid, float ve, float y);

private:
	sf::Sprite *sprite, *sprite1;
	float width, vel, yPos;
};

