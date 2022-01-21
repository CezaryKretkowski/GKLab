//
// Created by cezar on 25.11.2021.
//
#include "SpriteObject.h"
#include <iostream>
void SpriteObject::animate(sf::RenderWindow *parent,bool start) {

    ts.update(*i);
    draw(parent);
    if(iter>((int)imges.size()-2)*10){
        iter=0;
        i=imges.begin();
    }
    iter++;
    if(iter%10==0)
    i++;

}
void SpriteObject::init(){
    ts.loadFromImage(img);
    i=imges.begin();
}
void SpriteObject::draw(sf::RenderWindow *parent) {

    this->painter.setTexture(ts);
    painter.setPosition(posX,posY);
    parent->draw(painter);
}
