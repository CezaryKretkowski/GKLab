//
// Created by cezar on 29.10.2021.
//

#include "Button.h"
#include <iostream>
void Button::setImages(std::string p1, std::string p2, std::string p3) {
    this->s1.loadFromFile(p1);
    this->s2.loadFromFile(p2);
    this->s3.loadFromFile(p3);
    source.loadFromImage(s1);
    painer.setTexture(source);
    painer.setPosition(posX,posY);

    //painer.setTextureRect();

}

Button::Button() {

}

void Button::onSelected(sf::RenderWindow * parent,sf::Event event) {

    int x;
    int y;

    if(event.type=sf::Event::MouseMoved){
        x=event.mouseMove.x;
        y=event.mouseMove.y;
    }

    if(x>=posX&&x<=(posX+width)&&y>=posY&&y<=(posY+hight))
    {
        source.update(s2);
        painer.setTexture(source);
        parent->draw(painer);

    }else{
        source.update(s1);
        painer.setTexture(source);
        parent->draw(painer);
    }

}

