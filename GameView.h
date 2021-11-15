//
// Created by cezar on 11.11.2021.
//

#ifndef GKLAB_GAMEVIEW_H
#define GKLAB_GAMEVIEW_H
#include "Tank.h"
class GameView{
private:
    Tank player1;
public:
    Tank* getTank(){return &player1;};
};
#endif //GKLAB_GAMEVIEW_H
