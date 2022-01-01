//
// Created by cezar on 11.11.2021.
//
#include <iostream>
#include "GameFun.h"
#include "MenuFun.h"
void randomObstycel(Engine *super);
void GameRun(Engine *super){
    super->clear(sf::Color::Black);
    super->game.background.draw(super->getFrame());
    super->game.pauseKey();
    if(super->game.getPasue())
    {
        std::cout<<"works"<<std::endl;
        super->getFrame()->draw(super->game.pauseMenu.getTitle()->getText());
        super->game.pauseMenu.GetExit()->onSelected(super->getFrame(),super->getEvent());
        super->game.pauseMenu.GetSaveAndExit()->onSelected(super->getFrame(),super->getEvent());

        if(super->game.pauseMenu.GetSaveAndExit()->onClicked(super->getFrame(),super->getEvent())){
            super->game.saveToFile(
                    Point2D(super->game.getPlayer1()->getTank()->getPosX(),super->game.getPlayer1()->getTank()->getPosY()),
                    Point2D(super->game.getPlayer2()->getTank()->getPosX(),super->game.getPlayer2()->getTank()->getPosY()),
                    super->game.getPlayer1()->getTank()->getSkin(),
                    super->game.getPlayer2()->getTank()->getSkin(),
                    super->game.getObtycleList(),
                    super->game.getPlayer1()->getPoints(),
                    super->game.getPlayer2()->getPoints()
                    );
            super->game.setPasue(false);
            super->setEnd(true);
            std::cout<<"Reload startet"<<std::endl;
            super->overrideSetUpFun(NULL);
            super->overrideRunFun(NULL);
            super->overrideSetUpFun(&menuSetUp);
            super->overrideRunFun(&menuRun);
            super->reload();
        }
        if(super->game.pauseMenu.GetExit()->onClicked(super->getFrame(),super->getEvent())){
            super->game.setPasue(false);
            super->setEnd(true);

            std::cout<<"Reload startet"<<std::endl;
            super->overrideSetUpFun(NULL);
            super->overrideRunFun(NULL);
            super->overrideSetUpFun(&menuSetUp);
            super->overrideRunFun(&menuRun);
            super->reload();
        }


    }else
    if((super->game.getPlayer1()->getPoints()==0)||(super->game.getPlayer2()->getPoints()==0)){
        if(super->game.getPlayer1()->getPoints()==0){
            super->game.endGame.getTitle()->setString("End Game Player 2 Win");
            std::cout<<"Koniec gry Palyr 2 Win"<<std::endl;}
        else{
            super->game.endGame.getTitle()->setString("End Game Player 1 Win");
            std::cout<<"Koniec gry Palyr 1 Win"<<std::endl;
        }
        super->getFrame()->draw(super->game.endGame.getTitle()->getText());
        super->game.endGame.GetExit()->onSelected(super->getFrame(),super->getEvent());
        if(super->game.endGame.GetExit()->onClicked(super->getFrame(),super->getEvent())){
            super->game.setPasue(false);
            super->setEnd(true);
            super->game.getPlayer1()->setPoints(10);
            super->game.getPlayer2()->setPoints(10);
            std::cout<<"Reload startet"<<std::endl;
            super->overrideSetUpFun(NULL);
            super->overrideRunFun(NULL);
            super->overrideSetUpFun(&menuSetUp);
            super->overrideRunFun(&menuRun);
            super->reload();
        }


    }
    else


    {
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
    if(super->game.getLoad()){
        super->game.loadFromFile();
       super->game.setLoad(false);}
    else {
        super->game.getPlayer1()->setUpTank(super->game.getObtycleList(), "Resource/image/Typical.png",
                                            "Resource/image/Missile.png", sf::Keyboard::W,
                                            sf::Keyboard::S, sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::Space);
        super->game.getPlayer1()->getTank()->setPosX(500);
        super->game.getPlayer1()->getTank()->setPosY(500);

        super->game.getPlayer2()->setUpTank(super->game.getObtycleList(), "Resource/image/TeDek.png",
                                            "Resource/image/Missile.png", sf::Keyboard::Up,
                                            sf::Keyboard::Down, sf::Keyboard::Right, sf::Keyboard::Left,
                                            sf::Keyboard::P);
        randomObstycel(super);
    }
        super->game.background.loadFromFille("Resource/image/map5.jpg");
        super->game.getLabel()->setColor(sf::Color::Red);
        super->game.getLabel()->setString("P1 :" + std::to_string(super->game.getPlayer1()->getPoints()) + "/P2 :" +
                                          std::to_string(super->game.getPlayer2()->getPoints()));
        super->game.getLabel()->setFont("gunplay.ttf");
        super->game.getLabel()->setSize(25);
        Point2D p(600.0, 20.0);
        super->game.getLabel()->setPos(p);

        super->game.pauseMenu.getTitle()->setString("Pause");
        super->game.pauseMenu.getTitle()->setSize(25);
        super->game.pauseMenu.getTitle()->setFont("gunplay.ttf");
        super->game.pauseMenu.getTitle()->setPos(Point2D(380, 100));
        super->game.pauseMenu.GetExit()->setPosX(250.0);
        super->game.pauseMenu.GetExit()->setPosY(430.0);
        super->game.pauseMenu.GetExit()->setWidth(300);
        super->game.pauseMenu.GetExit()->setHight(50);
        super->game.pauseMenu.GetExit()->setImages("Resource/image/base5.png", "Resource/image/selected5.png",
                                                   "Resource/image/clicked.png");


        super->game.pauseMenu.GetSaveAndExit()->setPosX(250.0);
        super->game.pauseMenu.GetSaveAndExit()->setPosY(330.0);
        super->game.pauseMenu.GetSaveAndExit()->setWidth(300);
        super->game.pauseMenu.GetSaveAndExit()->setHight(50);
        super->game.pauseMenu.GetSaveAndExit()->setImages("Resource/image/base6.png", "Resource/image/selected6.png",
                                                          "Resource/image/clicked.png");

    super->game.endGame.GetExit()->setPosX(250.0);
    super->game.endGame.GetExit()->setPosY(430.0);
    super->game.endGame.GetExit()->setWidth(300);
    super->game.endGame.GetExit()->setHight(50);
        super->game.endGame.GetExit()->setImages("Resource/image/base5.png", "Resource/image/selected5.png",
                                                   "Resource/image/clicked.png");

        super->game.endGame.getTitle()->setSize(25);
        super->game.endGame.getTitle()->setFont("gunplay.ttf");
        super->game.endGame.getTitle()->setPos(Point2D(280, 100));

}
void GameClear(Engine *super){

}
void randomObstycel(Engine *super){
    Obstycle testeing;
    testeing.setPosY(400);
    testeing.setPosX(300);
    testeing.setImg("Resource/image/skaly/obj1.png");
    super->game.addObstycle(testeing);
    Obstycle testeing1;
    testeing1.setPosY(100);
    testeing1.setPosX(200);
    testeing1.setImg("Resource/image/skaly/obj2.png");
    super->game.addObstycle(testeing1);

    Obstycle testeing2;
    testeing2.setPosY(70);
    testeing2.setPosX(543);
    testeing2.setImg("Resource/image/skaly/obj3.png");
    super->game.addObstycle(testeing2);

    Obstycle testeing3;
    testeing3.setPosY(500);
    testeing3.setPosX(321);
    testeing3.setImg("Resource/image/skaly/obj4.png");
    super->game.addObstycle(testeing3);


    Obstycle testeing4;
    testeing4.setPosY(200);
    testeing4.setPosX(450);
    testeing4.setImg("Resource/image/skaly/obj5.png");
    super->game.addObstycle(testeing4);

}
