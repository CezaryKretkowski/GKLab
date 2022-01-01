//
// Created by cezar on 29.10.2021.
//
#include "MenuFun.h"
#include <iostream>
#include "GameFun.h"
#include "OnlineGameViewFun.h"
void ecapeEnd(Engine *parent){
    parent->setEnd(false);
    parent->getFrame()->close();
    std::cout<<"działa"<<std::endl;
}
void menuRun(Engine *super) {
    super->clear(super->menu.getBackGround());
    super->getFrame()->draw(super->menu.getLabel()->getText());
    super->menu.newGame.onSelected(super->getFrame(),super->getEvent());
    if(super->menu.newGame.onClicked(super->getFrame(),super->getEvent())){
        super->setEnd(true);
        super->game.setLoad(false);
        std::cout<<"Reload startet"<<std::endl;
        super->overrideSetUpFun(NULL);
        super->overrideRunFun(NULL);
        super->overrideSetUpFun(&GameSetUp);
        super->overrideRunFun(&GameRun);
        super->reload();
    }
    super->menu.loadGame.onSelected(super->getFrame(),super->getEvent());
    if(super->menu.loadGame.onClicked(super->getFrame(),super->getEvent())){
        super->setEnd(true);
        std::cout<<"Reload startet"<<std::endl;
        super->overrideSetUpFun(NULL);
        super->overrideRunFun(NULL);
        super->overrideSetUpFun(&GameSetUp);
        super->overrideRunFun(&GameRun);
        super->game.setLoad(true);
        super->reload();
    }
    super->menu.onlineGame.onSelected(super->getFrame(),super->getEvent());
    if(super->menu.onlineGame.onClicked(super->getFrame(),super->getEvent())){
        super->setEnd(true);
        super->overrideSetUpFun(NULL);
        super->overrideRunFun(NULL);
        super->overrideSetUpFun(&onlineGameSetUP);
        super->overrideRunFun(&onlineGameRun);
        super->reload();

    }
    super->menu.endButton.onSelected(super->getFrame(),super->getEvent());
    if(super->menu.endButton.onClicked(super->getFrame(),super->getEvent())){
        super->setEnd(true);
        super->getFrame()->close();
    }
}

void menuSetUp(Engine *super) {
    KeyListener end(sf::Keyboard::G,&ecapeEnd);
    super->addKeyListener(end);
    super->menu.setBackground("Menu2.jpg");
    super->getSource()->loadFromImage(super->menu.getBackGround());
    super->menu.getLabel()->setColor(sf::Color::Red);
    super->menu.getLabel()->setString("Tanks");
    super->menu.getLabel()->setFont("gunplay.ttf");
    super->menu.getLabel()->setSize(50);
    Point2D p(320.0,20.0);
    super->menu.getLabel()->setPos(p);


    super->menu.newGame.setPosX(250.0);
    super->menu.newGame.setPosY(130.0);
    super->menu.newGame.setWidth(300);
    super->menu.newGame.setHight(50);
    super->menu.newGame.setImages("Resource/image/base.png","Resource/image/selected.png","Resource/image/clicked.png");

    super->menu.loadGame.setPosX(250.0);
    super->menu.loadGame.setPosY(230.0);
    super->menu.loadGame.setWidth(300);
    super->menu.loadGame.setHight(50);
    super->menu.loadGame.setImages("Resource/image/base4.png","Resource/image/selected4.png","Resource/image/clicked.png");

    super->menu.onlineGame.setPosX(250.0);
    super->menu.onlineGame.setPosY(330.0);
    super->menu.onlineGame.setWidth(300);
    super->menu.onlineGame.setHight(50);
    super->menu.onlineGame.setImages("Resource/image/base1.png","Resource/image/selected1.png","Resource/image/clicked.png");


    super->menu.endButton.setPosX(250.0);
    super->menu.endButton.setPosY(430.0);
    super->menu.endButton.setWidth(300);
    super->menu.endButton.setHight(50);
    super->menu.endButton.setImages("Resource/image/base2.png","Resource/image/selected2.png","Resource/image/clicked.png");


}
void menuClear(Engine *super){
    super->overrideRunFun(NULL);
    super->overrideSetUpFun(NULL);
    super->clearKeys();

}
