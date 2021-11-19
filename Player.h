//
// Created by cezar on 19.11.2021.
//

#ifndef GKLAB_PLAYER_H
#define GKLAB_PLAYER_H
#include "Tank.h"
#include "Point2D.h"
class Player{
    Tank tank;
    Point2D missileCoords;
public:
    Tank* getTank(){return &tank;}
    Point2D* getMissileCords(){return &missileCoords;}
    void  setUpTank(std::vector<Obstycle>* obstycle,std::string skin,std::string missile,sf::Keyboard::Key up,sf::Keyboard::Key down,sf::Keyboard::Key left
    ,sf::Keyboard::Key right,sf::Keyboard::Key fire);

};
#endif //GKLAB_PLAYER_H
