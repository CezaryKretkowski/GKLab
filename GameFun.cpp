//
// Created by cezar on 11.11.2021.
//
#include <iostream>
#include "GameFun.h"
void GameRun(Engine *super){
    super->clear(sf::Color::Black);
    super->game.getTank()->draw(super->getFrame());
    super->game.getTank()->moveUp(super->getFrame());
    super->game.getTank()->moveDown(super->getFrame());
    super->game.getTank()->rotLeft(super->getFrame());
    super->game.getTank()->rotRight(super->getFrame());
    super->game.getTank()->fireFun(super->getFrame());
    super->game.getTank()->drawMissile(super->getFrame());
}
void GameSetUp(Engine *super){
    super->game.getTank()->setSkin("Resource/image/Tank1.png");
    super->game.getTank()->setPosX(100.0);
    super->game.getTank()->setPosY(100.0);
    super->game.getTank()->setAngel(0.0);
    super->game.getTank()->ofset.x=15;
    super->game.getTank()->ofset.y=25;
    super->game.getTank()->setUpKey(sf::Keyboard::W);
    super->game.getTank()->setDownKey(sf::Keyboard::S);
    super->game.getTank()->setLeftKey(sf::Keyboard::A);
    super->game.getTank()->setRightKey(sf::Keyboard::D);
    super->game.getTank()->setFireKey(sf::Keyboard::Space);
    super->game.getTank()->getMissile()->setImg("Resource/image/Missile.png");

}
void GameClear(Engine *super){


}
