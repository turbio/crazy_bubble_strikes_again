#include "InfinitePan.h"


InfinitePan::InfinitePan(void){

}


InfinitePan::~InfinitePan(void){

}

sf::Sprite* InfinitePan::setSprite(sf::Sprite *spr, float with, float ve, float y){
	sprite = spr;
	sprite1 = new sf::Sprite(*spr);

	sprite->setPosition(0, y);
	sprite1->setPosition(with, y);

	width = with;
	InfinitePan::vel = ve;
	InfinitePan::yPos = y;

	return sprite1;
}

void InfinitePan::update(double delta){
	sprite->move(vel * delta, 0);
	sprite1->move(vel * delta, 0);

	if(sprite->getPosition().x < -width + 5){
		sprite->setPosition(width, yPos);
	}
	if(sprite1->getPosition().x < -width + 5){
		sprite1->setPosition(width, yPos);
	}

}