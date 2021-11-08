//
// Created by cezar on 29.10.2021.
//

#ifndef GKLAB_MAINMENU_H
#define GKLAB_MAINMENU_H
#include <SFML/Graphics.hpp>
#include "Label.h"
#include "Button.h"

class MainMenu{
private:
    sf::Image background;
    Label header;


public:
    Button newGame;
    Button onlineGame;
    Button endButton;
    void setBackground(std::string path);
    sf::Image getBackGround();
    Label* getLabel();
};
#endif //GKLAB_MAINMENU_H
