//
// Created by cezar on 01.01.2022.
//
#include "OnlineGameViewFun.h"
#include "ClientServer.h"
#include "../MenuFun.h"
void LoadMapObstycel(Engine *super);
void DrawOponent(Engine* super,float Data[4]);
void onlineGameSetUP(Engine* super){
    super->onlineGame.background.loadFromFille("Resource/image/map5.jpg");

    super->onlineGame.scren.getTitle()->setString("Conection Screen");
    super->onlineGame.scren.getTitle()->setSize(25);
    super->onlineGame.scren.getTitle()->setFont("gunplay.ttf");
    super->onlineGame.scren.getTitle()->setPos(Point2D(310, 100));
    super->onlineGame.scren.GetCreteGame()->setPosX(250.0);
    super->onlineGame.scren.GetCreteGame()->setPosY(430.0);
    super->onlineGame.scren.GetCreteGame()->setWidth(300);
    super->onlineGame.scren.GetCreteGame()->setHight(50);
    super->onlineGame.scren.GetCreteGame()->setImages("Resource/image/base7.png", "Resource/image/selected7.png",
                                               "Resource/image/clicked.png");


    super->onlineGame.scren.GetJoinGame()->setPosX(250.0);
    super->onlineGame.scren.GetJoinGame()->setPosY(330.0);
    super->onlineGame.scren.GetJoinGame()->setWidth(300);
    super->onlineGame.scren.GetJoinGame()->setHight(50);
    super->onlineGame.scren.GetJoinGame()->setImages("Resource/image/base8.png", "Resource/image/selected8.png",
                                                      "Resource/image/clicked.png");

    LoadMapObstycel(super);

    super->onlineGame.getPlayer1()->setUpTank(super->onlineGame.getObtycleList(), "Resource/image/Typical.png",
                                              "Resource/image/Missile.png", sf::Keyboard::W,
                                              sf::Keyboard::S, sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::Space);
    super->onlineGame.getPlayer2()->setUpTank(super->onlineGame.getObtycleList(), "Resource/image/TeDek.png",
                                              "Resource/image/Missile.png", sf::Keyboard::W,
                                              sf::Keyboard::S, sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::Space);


    super->onlineGame.getPlayer1()->getTank()->setPosX(500);
    super->onlineGame.getPlayer1()->getTank()->setPosY(500);


    super->onlineGame.getPlayer2()->getTank()->setPosX(100);
    super->onlineGame.getPlayer2()->getTank()->setPosY(100);


    super->onlineGame.getLabel()->setColor(sf::Color::Red);
    super->onlineGame.getLabel()->setString("P1 :" + std::to_string(super->game.getPlayer1()->getPoints()) + "/P2 :" +
                                            std::to_string(super->game.getPlayer2()->getPoints()));
    super->onlineGame.getLabel()->setFont("gunplay.ttf");
    super->onlineGame.getLabel()->setSize(25);
    Point2D p(600.0, 20.0);
    super->onlineGame.getLabel()->setPos(p);


    super->game.endGame.GetExit()->setPosX(250.0);
    super->game.endGame.GetExit()->setPosY(430.0);
    super->game.endGame.GetExit()->setWidth(300);
    super->game.endGame.GetExit()->setHight(50);
    super->game.endGame.GetExit()->setImages("Resource/image/base5.png", "Resource/image/selected5.png",
                                             "Resource/image/clicked.png");

    super->game.endGame.getTitle()->setSize(25);
    super->game.endGame.getTitle()->setFont("gunplay.ttf");
    super->game.endGame.getTitle()->setPos(Point2D(280, 100));
    super->onlineGame.getPlayer1()->getTank()->loadExsploutionSound("Resource/Sounds/explosion.wav");
    super->onlineGame.getPlayer2()->getTank()->loadExsploutionSound("Resource/Sounds/explosion.wav");



}
void onlineGameRun(Engine* super){
    super->clear(sf::Color::Black);
    super->onlineGame.background.draw(super->getFrame());
    if(!super->onlineGame.conection){
        super->getFrame()->draw(super->onlineGame.scren.getTitle()->getText());
        super->onlineGame.scren.GetJoinGame()->onSelected(super->getFrame(),super->getEvent());
        super->onlineGame.scren.GetCreteGame()->onSelected(super->getFrame(),super->getEvent());
        if(super->onlineGame.scren.GetJoinGame()->onClicked(super->getFrame(),super->getEvent())){
            puts("Client ----------------------");
            super->onlineGame.networkClass.serverRole= false;
            float data[4];
            super->onlineGame.networkClass.port=5000;
            if (super->onlineGame.networkClass.SendPos(1, 2, 3,4))
                puts("Wiadomość poprawnie wysłana ");
            if (super->onlineGame.networkClass.Receive(data))
                printf("Odebrano wiadomość : %f %f %f %f \n", data[0], data[1], data[2], data[3]);
            else
                puts("Nieudało się odebrać wiadomości ");
            if( data[0]==1 && data[1]==2&& data[2]==3&& data[3]==4){
                super->onlineGame.conection=true;
            super->onlineGame.networkClass.socket.setBlocking(false);
            }
        }
        if(super->onlineGame.scren.GetCreteGame()->onClicked(super->getFrame(),super->getEvent())){
            puts("Server ----------------------");
            float data[4];
            super->onlineGame.networkClass.serverRole= true;
            super->onlineGame.networkClass.port=5000;
            if(super->onlineGame.networkClass.Bind())
                puts("Nasłuchuje na porcie 5000");
            if (super->onlineGame.networkClass.Receive(data))
                printf("Odebrano wiadomość : %f %f %f %f \n", data[0], data[1], data[2], data[3]);
            else
                puts("Nieudało się odebrać wiadomości ");
            if (super->onlineGame.networkClass.SendPos(data[0], data[1], data[2], data[3]))
                puts("Wiadomość poprawnie wysłana ");
            if( data[0]==1 && data[1]==2&& data[2]==3&& data[3]==4) {
                super->onlineGame.conection = true;
                super->onlineGame.networkClass.socket.setBlocking(false);
            }
        }
    }else if ((super->onlineGame.getPlayer1()->getPoints() < 0) || (super->onlineGame.getPlayer2()->getPoints() < 0)) {




        if (super->onlineGame.getPlayer1()->getPoints() == 0) {
            super->game.endGame.getTitle()->setString("End Game Player 2 Win");
            std::cout << "Koniec gry Palyr 2 Win" << std::endl;
        } else {
            super->game.endGame.getTitle()->setString("End Game Player 1 Win");
            std::cout << "Koniec gry Palyr 1 Win" << std::endl;
        }
        super->getFrame()->draw(super->game.endGame.getTitle()->getText());
        super->game.endGame.GetExit()->onSelected(super->getFrame(), super->getEvent());
        if (super->game.endGame.GetExit()->onClicked(super->getFrame(), super->getEvent())) {

            super->setEnd(true);
            super->onlineGame.getPlayer1()->setPoints(10);
            super->onlineGame.getPlayer2()->setPoints(10);
            std::cout << "Reload startet" << std::endl;
            super->overrideSetUpFun(NULL);
            super->overrideRunFun(NULL);
            super->overrideSetUpFun(&menuSetUp);
            super->overrideRunFun(&menuRun);
            super->reload();
        }


    }


    else{
        double fire=0;
        int i=0;
        super->onlineGame.getLabel()->setString("P1 :"+std::to_string(super->onlineGame.getPlayer1()->getPoints())+ "/P2 :"+std::to_string(super->onlineGame.getPlayer2()->getPoints())  );



        super->onlineGame.getPlayer1()->getTank()->draw(super->getFrame());
        super->onlineGame.getPlayer1()->getTank()->moveUp(super->getFrame());
        super->onlineGame.getPlayer1()->getTank()->moveDown(super->getFrame());
        super->onlineGame.getPlayer1()->getTank()->rotLeft(super->getFrame());
        super->onlineGame.getPlayer1()->getTank()->rotRight(super->getFrame());
        super->onlineGame.getPlayer1()->getTank()->fireFun(super->getFrame());
        super->onlineGame.getPlayer1()->getTank()->drawMissile(super->getFrame(),super->getClock(),super->game.getPlayer1()->getMissileCords());
        super->getFrame()->draw(super->onlineGame.getLabel()->getText());



        super->onlineGame.drawObstycles(super->getFrame());
        if(super->onlineGame.getPlayer1()->getTank()->getLoad())
            fire=1;
        else
            fire=0;

        super->onlineGame.networkClass.SendPos(super->onlineGame.getPlayer1()->getTank()->getPosX(),super->onlineGame.getPlayer1()->getTank()->getPosY(),
                                               super->onlineGame.getPlayer1()->getTank()->getAngle(),
                                               super->onlineGame.getPlayer1()->getMissileCords()->getX(),
                                               super->onlineGame.getPlayer1()->getMissileCords()->getY(),
                                               super->onlineGame.getPlayer1()->getPoints(),fire);

        if(super->onlineGame.networkClass.Receive(super->onlineGame.networkClass.buffer)){
            DrawOponent(super,super->onlineGame.networkClass.buffer);
        }

        if (super->onlineGame.getPlayer1()->getTank()->checkHit(super->onlineGame.getPlayer2()->getMissileCords(), 0)) {
            puts("hitt");
            i++;
            // super->onlineGame.getPlayer2()->setMissileCoords();
        } if(i<0){
            super->onlineGame.getPlayer1()->setPoints(super->onlineGame.getPlayer1()->getPoints() - 1);
        }
            super->onlineGame.getPlayer2()->getTank()->drawMissile(super->getFrame(),super->getClock(),super->onlineGame.getPlayer2()->getMissileCords());
        //  printf("Player2 %f  , %f\n",super->onlineGame.getPlayer1()->getMissileCords()->getX(),super->onlineGame.getPlayer1()->getMissileCords()->getY());


        super->onlineGame.getPlayer2()->getTank()->draw(super->getFrame());
        super->onlineGame.getPlayer2()->getTank()->fireFun(super->getFrame(),super->onlineGame.networkClass.buffer[6]);



    }
}
void onlineGameClear(Engine* super){

}
void DrawOponent(Engine* super,float Data[7]){
    if(Data[0]!=super->onlineGame.getPlayer2()->getTank()->getPosX())
    super->onlineGame.getPlayer2()->getTank()->setPosX(Data[0]);
    if(Data[1]!=super->onlineGame.getPlayer2()->getTank()->getPosY())
    super->onlineGame.getPlayer2()->getTank()->setPosY(Data[1]);
    if(Data[2]!=super->onlineGame.getPlayer2()->getTank()->getAngle())
        super->onlineGame.getPlayer2()->getTank()->setAngel(Data[2]);

    if(Data[3]!=super->onlineGame.getPlayer2()->getMissileCords()->getX())
        super->onlineGame.getPlayer2()->getMissileCords()->setX(Data[3]);
    if(Data[4]!=super->onlineGame.getPlayer2()->getMissileCords()->getY())
        super->onlineGame.getPlayer2()->getMissileCords()->setY(Data[4]);
    if(Data[5]!=super->onlineGame.getPlayer2()->getPoints())
        super->onlineGame.getPlayer2()->setPoints(Data[5]);
    if(Data[5]==0)
        super->onlineGame.getPlayer2()->setPoints(Data[5]-1);


}
void LoadMapObstycel(Engine *super){
    Obstycle testeing;
    testeing.setPosY(400);
    testeing.setPosX(300);
    testeing.setImg("Resource/image/skaly/obj1.png");
    super->onlineGame.addObstycle(testeing);
    Obstycle testeing1;
    testeing1.setPosY(100);
    testeing1.setPosX(200);
    testeing1.setImg("Resource/image/skaly/obj2.png");
    super->onlineGame.addObstycle(testeing1);

    Obstycle testeing2;
    testeing2.setPosY(70);
    testeing2.setPosX(543);
    testeing2.setImg("Resource/image/skaly/obj3.png");
    super->onlineGame.addObstycle(testeing2);

    Obstycle testeing3;
    testeing3.setPosY(500);
    testeing3.setPosX(321);
    testeing3.setImg("Resource/image/skaly/obj4.png");
    super->onlineGame.addObstycle(testeing3);


    Obstycle testeing4;
    testeing4.setPosY(200);
    testeing4.setPosX(450);
    testeing4.setImg("Resource/image/skaly/obj5.png");
    super->onlineGame.addObstycle(testeing4);

}

