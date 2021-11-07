//
// Created by cezar on 29.10.2021.
//
#include "MainMenu.h"
void MainMenu::setBackground(std::string filName) {
    std::string path="Resource/image/"+filName;
    this->background.loadFromFile(path);
}
sf::Image MainMenu::getBackGround() {
    return this->background;
}
Label* MainMenu::getLabel() {
    return &header;
}
