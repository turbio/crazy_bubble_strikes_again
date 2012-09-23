#pragma once

#include <vector>
#include <SFML\Graphics.hpp>

class MultiSprite{

public:
	MultiSprite(void);
	~MultiSprite(void);
	sf::Sprite* addSprite(sf::Sprite*);
	sf::Sprite* getSprite(int);
	void rotate(float amount);
	void move(float x, float y);
	void bob(float max, float min, float speed);

private:
	std::vector<sf::Sprite*> sprites;
	float xPos, yPos, rot;
	bool bobleUp;
};

