#include "LogicHandler.h"

#define WIDTH 640
#define HEIGHT 480
#define TITLE "The Incredible Florist Adventure"

sf::RectangleShape shape;

//CONSTRUCTOR
LogicHandler::LogicHandler(void){
	titleScreen = true;
	elapsedTime = 1;

	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close);

	shape.setSize(sf::Vector2f(10.0f, 10.0f));
	if(!LogicHandler::loadTextures("res/")){
		shape.setFillColor(sf::Color::Red);
		std::cout << "FAILDED TO LOAD ALL FILES" << std::endl;
		sf::sleep(sf::milliseconds(10000));	//sleep for 10 seconds
		return;
	}else{
		shape.setFillColor(sf::Color::Green);
	}

	titleScreenBg.setTexture(*textureList.at(0));
	titleScreenBg.setPosition(0, 0);

	setupSprites();

	window->setFramerateLimit(0);
}

void LogicHandler::setupSprites(void){

}

//DESTRUCTOR
LogicHandler::~LogicHandler(void){

}

void LogicHandler::run(void){

	double deltaTime = 1, startTime = 0;
	sf::Clock clock;
	clock.restart();
	while (window->isOpen()){
		sf::Event event;
		while (window->pollEvent(event)){
			handleEvent(event);
        }

		startTime = clock.getElapsedTime().asMilliseconds();

		LogicHandler::update(deltaTime);
		window->clear(sf::Color(20, 180, 255));

		for(int i = 0; i < spriteList.size(); i++){
			window->draw(*spriteList.at(i));
		}

		window->draw(shape);
		shape.move(1 * deltaTime, 0);

		std::cout << deltaTime << std::endl;

		deltaTime = clock.getElapsedTime().asMilliseconds() - startTime + 1;

		window->display();
    }
}

void LogicHandler::update(double delta){
	elapsedTime += (delta * 0.1);

}

void LogicHandler::handleEvent(sf::Event evt){
	if (evt.type == sf::Event::Closed){
		window->close();
	}else if((evt.type == sf::Event::KeyPressed ||
		evt.type == sf::Event::MouseButtonPressed) && titleScreen){
			titleScreen = false;
	}
}

bool LogicHandler::loadTextures(std::string dir){
	std::string line;
	std::vector<sf::Texture*> textures;

	std::ifstream file(dir + "res.txt");

	if(file.is_open()){
		while(file.good()){
			std::getline(file, line);
			
			std::cout << "res: " << line;

			sf::Texture *tex;
			tex = new sf::Texture;
			if(!tex->loadFromFile( dir + line)){
				return false;
			}
			textures.push_back(tex);
			
			std::cout << " loaded" << std::endl;
		}
		file.close();
	}else{
		return false;
	}

	textureList = textures;
	return true;
}
