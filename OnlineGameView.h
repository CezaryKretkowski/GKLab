//
// Created by cezar on 30.12.2021.
//

#ifndef GKLAB_ONLINEGAMEVIEW_H
#define GKLAB_ONLINEGAMEVIEW_H
#include "Obstycle.h"
#include <vector>
#include "Player.h"
#include "Label.h"
#include <list>
#include "Button.h"
#include "Pause.h"
#include "BitmapHandler.h"
#include "EndGame.h"
#include "ConectingScreen.h"
#include "ClientServer.h"
class OnlineGameView{
private:
    Player player1;
    Player player2;
    std::vector<Obstycle> obstycle;
    Label wynik;
public :
    ClientServer networkClass;
    bool conection=false;
    ConectingScreen scren;
    BitmapHandler background;
    Player* getPlayer1(){return &player1;};
    Player* getPlayer2(){return &player2;};
    std::vector<Obstycle>* getObtycleList();
    void drawObstycles(sf::RenderWindow *parent);
    Label* getLabel(){return &wynik;};
    void addObstycle(Obstycle o);

};
#endif //GKLAB_ONLINEGAMEVIEW_H
