//
// Created by cezar on 11.11.2021.
//
#include <iostream>
#include "GameFun.h"
#include "MenuFun.h"
void GameRun(Engine *super){
    super->clear(sf::Color::Black);
    super->game.pauseKey();
    if(super->game.getPasue())
    {
        std::cout<<"works"<<std::endl;
        super->getFrame()->draw(super->game.pauseMenu.getTitle()->getText());
        super->game.pauseMenu.GetExit()->onSelected(super->getFrame(),super->getEvent());
        super->game.pauseMenu.GetSaveAndExit()->onSelected(super->getFrame(),super->getEvent());

        if(super->game.pauseMenu.GetSaveAndExit()->onClicked(super->getFrame(),super->getEvent())){
            super->setEnd(true);
            std::cout<<"Reload startet"<<std::endl;
            super->overrideSetUpFun(NULL);
            super->overrideRunFun(NULL);
            super->overrideSetUpFun(&menuSetUp);
            super->overrideRunFun(&menuRun);
            super->reload();
        }
        if(super->game.pauseMenu.GetExit()->onClicked(super->getFrame(),super->getEvent())){
            super->setEnd(true);
            std::cout<<"Reload startet"<<std::endl;
            super->overrideSetUpFun(NULL);
            super->overrideRunFun(NULL);
            super->overrideSetUpFun(&menuSetUp);
            super->overrideRunFun(&menuRun);
            super->reload();
        }


    }else{
    super->game.getLabel()->setString("P1 :"+std::to_string(super->game.getPlayer1()->getPoints())+ "/P2 :"+std::to_string(super->game.getPlayer2()->getPoints())  );
    super->game.getPlayer1()->getTank()->draw(super->getFrame());
    super->game.getPlayer1()->getTank()->moveUp(super->getFrame());
    super->game.getPlayer1()->getTank()->moveDown(super->getFrame());
    super->game.getPlayer1()->getTank()->rotLeft(super->getFrame());
    super->game.getPlayer1()->getTank()->rotRight(super->getFrame());
    super->game.getPlayer1()->getTank()->fireFun(super->getFrame());
    super->game.getPlayer1()->getTank()->drawMissile(super->getFrame(),super->getClock(),super->game.getPlayer1()->getMissileCords());
    super->getFrame()->draw(super->game.getLabel()->getText());

    if(super->game.getPlayer1()->getTank()->checkHit(super->game.getPlayer2()->getMissileCords(),1)){
        super->game.getPlayer1()->setPoints(super->game.getPlayer1()->getPoints()-1);
    }
    super->game.drawObstycles(super->getFrame());


    super->game.getPlayer2()->getTank()->draw(super->getFrame());
    super->game.getPlayer2()->getTank()->moveUp(super->getFrame());
    super->game.getPlayer2()->getTank()->moveDown(super->getFrame());
    super->game.getPlayer2()->getTank()->rotLeft(super->getFrame());
    super->game.getPlayer2()->getTank()->rotRight(super->getFrame());
    super->game.getPlayer2()->getTank()->fireFun(super->getFrame());
    super->game.getPlayer2()->getTank()->drawMissile(super->getFrame(),super->getClock(),super->game.getPlayer2()->getMissileCords());
    if(super->game.getPlayer2()->getTank()->checkHit(super->game.getPlayer1()->getMissileCords(),2)){
        super->game.getPlayer2()->setPoints(super->game.getPlayer2()->getPoints()-1);
    }
    }

}
void GameSetUp(Engine *super){

    super->game.getPlayer1()->setUpTank(super->game.getObtycleList(),"Resource/image/Tank1.png","Resource/image/Missile.png",sf::Keyboard::W,
                                        sf::Keyboard::S,sf::Keyboard::D,sf::Keyboard::A,sf::Keyboard::Space);
    super->game.getPlayer2()->setUpTank(super->game.getObtycleList(),"Resource/image/Tank2.png","Resource/image/Missile.png",sf::Keyboard::Up,
                                        sf::Keyboard::Down,sf::Keyboard::Right,sf::Keyboard::Left,sf::Keyboard::P);
    Obstycle testeing;
    testeing.setPosY(400);
    testeing.setPosX(300);
    testeing.setImg("Resource/image/Obstycle1.png");
    super->game.addObstycle(testeing);
    Obstycle testeing1;
    testeing1.setPosY(100);
    testeing1.setPosX(200);
    testeing1.setImg("Resource/image/Obstycle2.png");
    super->game.addObstycle(testeing1);

    super->game.getLabel()->setColor(sf::Color::Red);
    super->game.getLabel()->setString("P1 :"+std::to_string(super->game.getPlayer1()->getPoints())+ "/P2 :"+std::to_string(super->game.getPlayer2()->getPoints()));
    super->game.getLabel()->setFont("gunplay.ttf");
    super->game.getLabel()->setSize(25);
    Point2D p(600.0,20.0);
    super->game.getLabel()->setPos(p);

    super->game.pauseMenu.getTitle()->setString("Pause");
    super->game.pauseMenu.getTitle()->setSize(25);
    super->game.pauseMenu.getTitle()->setFont("gunplay.ttf");
    super->game.pauseMenu.getTitle()->setPos( Point2D(380,100));
    super->game.pauseMenu.GetExit()->setPosX(250.0);
    super->game.pauseMenu.GetExit()->setPosY(430.0);
    super->game.pauseMenu.GetExit()->setWidth(300);
    super->game.pauseMenu.GetExit()->setHight(50);
    super->game.pauseMenu.GetExit()->setImages("Resource/image/base2.png","Resource/image/selected2.png","Resource/image/clicked.png");


    super->game.pauseMenu.GetSaveAndExit()->setPosX(250.0);
    super->game.pauseMenu.GetSaveAndExit()->setPosY(330.0);
    super->game.pauseMenu.GetSaveAndExit()->setWidth(300);
    super->game.pauseMenu.GetSaveAndExit()->setHight(50);
    super->game.pauseMenu.GetSaveAndExit()->setImages("Resource/image/base2.png","Resource/image/selected2.png","Resource/image/clicked.png");



}
void GameClear(Engine *super){


}
