//
// Created by cezar on 15.10.2021.
//
#include "MouseListener.h"
#include "Label.h"
#include <iostream>
void MouseListener::mouseMove(sf::RenderWindow *parent,sf::Event event) {
   if(event.type==sf::Event::MouseMoved) {
       this->x=event.mouseMove.x;
       this->y=event.mouseMove.y;
       if(this->onMouseMove!=NULL)
           onMouseMove(parent,this);
   }
}
void MouseListener::overrideMouseMove(void (*onMouseMove)(sf::RenderWindow *parent,MouseListener *This )) {
    this->onMouseMove=*onMouseMove;
}
void MouseListener::mouseButtonEnter(sf::RenderWindow *parent, sf::Event event) {
    if(event.type==sf::Event::MouseEntered&&this->onMouseEnter!=NULL)
        this->onMouseEnter(parent,this);
}
void MouseListener::overrideMouseEnter(void (*onMouseEnter)(sf::RenderWindow *, MouseListener *)) {
    this->onMouseEnter=*onMouseEnter;
}
void MouseListener::mouseButtonLeft(sf::RenderWindow *parent, sf::Event event) {
    if(event.type==sf::Event::MouseLeft&&this->onMouseLeft!=NULL)
        this->onMouseLeft(parent,this);
}
void MouseListener::overrideMouseLeft(void (*onMouseLeft)(sf::RenderWindow *, MouseListener *)) {
    this->onMouseLeft=*onMouseLeft;
}
void MouseListener::mouseButtonPressed(sf::RenderWindow *parent, sf::Event event) {
    if(event.type==sf::Event::MouseButtonPressed){
        if(event.mouseButton.button==sf::Mouse::Left&&onMouseButtonLeftPressed!=NULL)
            onMouseButtonLeftPressed(parent,this);
        if(event.mouseButton.button==sf::Mouse::Right&&onMouseButtonRightPressed!=NULL)
            onMouseButtonRightPressed(parent,this);
        if(event.mouseButton.button==sf::Mouse::Middle&&this->onMouseButtonScrollPressed!=NULL)
            onMouseButtonScrollPressed(parent,this);
    }
}
void MouseListener::mouseButtonReleased(sf::RenderWindow *parent, sf::Event event) {
    if(event.type==sf::Event::MouseButtonReleased){
        if(event.mouseButton.button==sf::Mouse::Left&&onMouseButtonLeftReleased!=NULL)
            onMouseButtonLeftReleased(parent,this);
        if(event.mouseButton.button==sf::Mouse::Right&&onMouseButtonRightReleased!=NULL)
            onMouseButtonRightReleased(parent,this);
        if(event.mouseButton.button==sf::Mouse::Middle&&this->onMouseButtonScrollReleased!=NULL)
            onMouseButtonScrollReleased(parent,this);
    }
}
void MouseListener::overrideMousePressed(void (*onMousePressed)(sf::RenderWindow *, MouseListener * This),int button) {
    switch (button) {
        case 1000:this->onMouseButtonLeftPressed=*onMousePressed;break;
        case 1001:this->onMouseButtonRightPressed=*onMousePressed;break;
        case 1002:this->onMouseButtonScrollPressed=*onMousePressed;break;
        default: std::cout<<"exepion"<<std::endl;break;//Dopisać obsługe wyjątku throw
    }

}
void MouseListener::overrideMouseReleased(void (*onMouseReleased)(sf::RenderWindow *, MouseListener * This),int button) {
    switch (button) {
        case 1000:this->onMouseButtonLeftReleased=*onMouseReleased;break;
        case 1001:this->onMouseButtonRightReleased=*onMouseReleased;break;
        case 1002:this->onMouseButtonScrollReleased=*onMouseReleased;break;
        default: std::cout<<"exepion"<<std::endl;break;//Dopisać obsługe wyjątku throw
    }

}
int MouseListener::getX(){
    return this->x;
}
int MouseListener::getY() {
    return this->y;
}