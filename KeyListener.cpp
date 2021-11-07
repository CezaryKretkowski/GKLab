//
// Created by cezary on 11.10.2021.
//
#include "KeyListener.h"
#include <iostream>
int i=0;
KeyListener::KeyListener(sf::Keyboard::Key key,void (*onKeyPressed)(Engine *parent)) {
   this->key=key;
    this->onKeyPressed=*onKeyPressed;
}
void KeyListener::onKeyPressedFun(Engine *parent) {
    if(onReleased!=NULL){
       onReleased(parent);
    }
    if(sf::Keyboard::isKeyPressed(key)){
        this->onKeyPressed(parent);
    }

}
void KeyListener::setOnKeyPressedFun(void (*onKeyPressed)(Engine *parent)) {
    this->onKeyPressed=*onKeyPressed;
}
void KeyListener::overrideRelesedFun(void (*onReleasedPressed)(Engine *)) {
    this->onReleased=*onReleasedPressed;
}
