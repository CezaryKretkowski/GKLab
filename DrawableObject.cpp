//
// Created by cezary on 15.11.2021.
//
#include "DrawableObject.h"
void DrawableObject::setImg(std::string path) {
    this->img.loadFromFile(path);
    this->ts.loadFromImage(img);
    this->painter.setTexture(ts);

}
void DrawableObject::draw(sf::RenderWindow *super) {

}
DrawableObject::~DrawableObject() {}


