//
// Created by cezary on 25.10.2021.
//
#include "Label.h"


Label::Label(std::string text, int size, std::string fontName, int x,int y, sf::Color color){
    this->text=text;
    this->font.loadFromFile(Path+fontName);
    this->color=color;
    this->size=size;
    this->posytion=Point2D((float)x,(float)y);
    this->label.setFont(font);
    this->label.setFillColor(color);
    this->label.setString(text);
    this->label.setPosition(x,y);

}
void Label::setString(std::string text){
    this->text=text;
    this->label.setString(text);
}
void Label::setFont(std::string fontName) {
    this->font.loadFromFile(Path+fontName);
    this->label.setFont(font);
}
void Label::setColor(sf::Color color) {
    this->color=color;
    this->label.setFillColor(color);
}
void Label::setSize(int size){
    this->size=size;
    this->label.setCharacterSize(size);
}
void Label::setPos(Point2D p) {
    this->posytion=p;
    this->label.setPosition(p.getX(),p.getY());
}
/*
void Label::draw(Engine *super) {

    super->getFrame()->draw(this->label);
}*/


