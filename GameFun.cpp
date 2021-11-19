//
// Created by cezar on 11.11.2021.
//
#include <iostream>
#include "GameFun.h"
void GameRun(Engine *super){
    super->clear(sf::Color::Black);
    super->game.getPlayer1()->getTank()->draw(super->getFrame());
    super->game.getPlayer1()->getTank()->moveUp(super->getFrame());
    super->game.getPlayer1()->getTank()->moveDown(super->getFrame());
    super->game.getPlayer1()->getTank()->rotLeft(super->getFrame());
    super->game.getPlayer1()->getTank()->rotRight(super->getFrame());
    super->game.getPlayer1()->getTank()->fireFun(super->getFrame());
    super->game.getPlayer1()->getTank()->drawMissile(super->getFrame(),super->getClock(),super->game.getPlayer1()->getMissileCords());

    super->game.getPlayer1()->getTank()->checkHit(super->game.getPlayer2()->getMissileCords(),1);
    super->game.drawObstycles(super->getFrame());


    super->game.getPlayer2()->getTank()->draw(super->getFrame());
    super->game.getPlayer2()->getTank()->moveUp(super->getFrame());
    super->game.getPlayer2()->getTank()->moveDown(super->getFrame());
    super->game.getPlayer2()->getTank()->rotLeft(super->getFrame());
    super->game.getPlayer2()->getTank()->rotRight(super->getFrame());
    super->game.getPlayer2()->getTank()->fireFun(super->getFrame());
    super->game.getPlayer2()->getTank()->drawMissile(super->getFrame(),super->getClock(),super->game.getPlayer2()->getMissileCords());
    super->game.getPlayer2()->getTank()->checkHit(super->game.getPlayer1()->getMissileCords(),2);

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



}
void GameClear(Engine *super){


}
