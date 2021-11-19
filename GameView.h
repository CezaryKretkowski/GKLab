//
// Created by cezar on 11.11.2021.
//

#ifndef GKLAB_GAMEVIEW_H
#define GKLAB_GAMEVIEW_H
#include "Tank.h"
#include <SFML/Graphics.hpp>
#include "Obstycle.h"
#include <vector>
#include "Player.h"
class GameView{
private:

    Player player1;
    Player player2;
    std::vector<Obstycle> obstycle;
public:
    void addObstycle(Obstycle o);
    Obstycle getObstycle(int index);
    //Obstycle testeing;
    Player* getPlayer1(){return &player1;};
    Player* getPlayer2(){return &player2;};
    void setPixelMap();
    int getPiksel(int x,int y);
    std::vector<Obstycle>* getObtycleList();
    void drawObstycles(sf::RenderWindow *parent);
};
#endif //GKLAB_GAMEVIEW_H
