//
// Created by cezar on 25.11.2021.
//
#include <iostream>
#include "BitmapHandler.h"
void BitmapHandler::loadFromFille(std::string path) {
    img.loadFromFile(path);
    texture.loadFromImage(img);

}
void BitmapHandler::draw(sf::RenderWindow *parent) {
    sr.setTexture(texture);
    parent->draw(sr);
}
void BitmapHandler::safeToFille(sf::RenderWindow* parent, std::string fillName) {
    texture.update(*parent);
    sf::Image im=texture.copyToImage();

    if(!im.saveToFile(fillName))
        std::cout<<"somthing went Wrong!!"<<std::endl;
}

