//
// Created by cezar on 12.11.2021.
//
#include "Missile.h"
Missile::Missile(float x, float y,int i) {
    posY=y;
    posX=x;
    count=i;
}
void Missile::setImg(std::string path) {
    img.loadFromFile(path);
    tx.loadFromImage(img);
    painter.setTexture(tx);
}
void Missile::draw(sf::RenderWindow *parent) {
    painter.setPosition(posX,posY);
    painter.setRotation(rot);
    parent->draw(painter);
}

