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
bool Button::onClicked(sf::RenderWindow *parent, sf::Event event) {

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            if(x>=posX&&x<=(posX+width)&&y>=posY&&y<=(posY+hight)){
                std::cout<<"na buttonie"<<std::endl;
                source.update(s3);
                painer.setTexture(source);
                parent->draw(painer);
                return true;
            }
    return false;
}
void Button::onSelected(sf::RenderWindow * parent,sf::Event event) {



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

