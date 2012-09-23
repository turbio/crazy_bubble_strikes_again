#pragma once

#include "InfinitePan.h"
#include <SFML\Graphics.hpp>	//uses graphics cuz itz a game dur
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>
#include "MultiSprite.h"

class LogicHandler{

public:
	LogicHandler(void);	//CONSTRUCTOR
	~LogicHandler(void);	//DESTRUCTOR
	void update(double delta_time);	//update game stuff
	void run(void);	//main game loop
	void setupSprites(void);

private:
	void handleEvent(sf::Event theEventToBeHandled);	//handles any and all events
	bool loadTextures(std::string directory);
	sf::RenderWindow *window;	//the main window (probobaly the only)
	std::vector<sf::Texture*> textureList;	//list of all textures currently loaded
	std::vector<sf::Sprite*> spriteList;	//list of all active sprites
	bool titleScreen;	//if the game is at the title screen
	double elapsedTime;	//total time elapsed
	MultiSprite player;	//player sprite
	sf::Sprite titleScreenBg;	//title screen background
};