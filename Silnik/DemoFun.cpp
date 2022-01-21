//
// Created by cezar on 26.11.2021.
//
#include "DemoFun.h"
void DemoRun(Engine*super){
    super->clear();
    super->demoGame.getP1()->moveRight(super->getFrame());
    super->demoGame.getP1()->moveUp(super->getFrame());
    super->demoGame.getP1()->moveDown(super->getFrame());
    super->demoGame.getP1()->moveLeft(super->getFrame());
    super->demoGame.getP1()->draw(super->getFrame());

}
void DemoSetUp(Engine*super){
    super->demoGame.getP1()->setPosX(100);
    super->demoGame.getP1()->setPosY(100);
    super->demoGame.getP1()->setImg("Resource/image/B0.png");
    super->demoGame.getP1()->setUpControl(sf::Keyboard::W,sf::Keyboard::S,sf::Keyboard::A,sf::Keyboard::D);
    super->demoGame.getP1()->loadRight("Resource/image/B0.png","Resource/image/B1.png","Resource/image/B2.png","Resource/image/B3.png");
    super->demoGame.getP1()->loadUp("Resource/image/B0.png","Resource/image/B1.png","Resource/image/B2.png","Resource/image/B3.png");
    super->demoGame.getP1()->loadDown("Resource/image/B0.png","Resource/image/B1.png","Resource/image/B2.png","Resource/image/B3.png");
    super->demoGame.getP1()->loadLeft("Resource/image/B0.png","Resource/image/B1.png","Resource/image/B2.png","Resource/image/B3.png");


}

