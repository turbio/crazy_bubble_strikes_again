#include "MultiSprite.h"


MultiSprite::MultiSprite(void){
	yPos = 0;
}

MultiSprite::~MultiSprite(void){

}

sf::Sprite* MultiSprite::addSprite(sf::Sprite *sprite){
	sprites.push_back(sprite);
	return sprite;
}

sf::Sprite* MultiSprite::getSprite(int i){
	return sprites.at(i);
}

void MultiSprite::move(float x, float y){
	for(int i = 0; i < sprites.size(); i++){
		sprites.at(i)->move(x, y);
	}
}

void MultiSprite::rotate(float rot){
	for(int i = 0; i < sprites.size(); i++){
		sprites.at(i)->rotate(rot);
	}
}

void MultiSprite::bob(float max, float min, float spd){
	if(bobleUp){
		if(yPos >= max){
			bobleUp = false;
		}else{
			yPos += spd;
			move(0.0f, spd);
		}
	}else{
		if(yPos <= min){
			bobleUp = true;
		}else{
			yPos -= spd;
			move(0.0f, -spd);
		}
	}
}