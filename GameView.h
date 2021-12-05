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
#include "Label.h"
#include <list>
#include "Button.h"
#include "Pause.h"
class GameView{
private:

    Player player1;
    Player player2;
    std::vector<Obstycle> obstycle;
    Label wynik;
    bool  load;
    bool pause=false;
    bool keyPressed=false;
public:

    Pause pauseMenu;
    void setLoad(bool load){this->load=load;}
    bool getLoad(){return load;}
    Label* getLabel(){return &wynik;};
    void addObstycle(Obstycle o);
    Obstycle getObstycle(int index);
    //Obstycle testeing;
    Player* getPlayer1(){return &player1;};
    Player* getPlayer2(){return &player2;};
    void setPixelMap();
    int getPiksel(int x,int y);
    std::vector<Obstycle>* getObtycleList();
    void drawObstycles(sf::RenderWindow *parent);
    void pauseKey();
    bool getPasue(){return pause;}
    void setPasue(bool pause){this->pause=pause;}
    void saveToFile(Point2D p1Pos,Point2D p2Pos,std::string skin1,std::string skin2,std::vector<Obstycle>* obs,int Point1,int Point2);
    void loadFromFile();
};
#endif //GKLAB_GAMEVIEW_H
