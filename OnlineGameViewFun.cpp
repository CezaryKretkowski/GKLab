//
// Created by cezar on 01.01.2022.
//
#include "OnlineGameViewFun.h"
#include "ClientServer.h"
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
            if( data[0]==1 && data[1]==2&& data[2]==3&& data[3]==4)
                super->onlineGame.conection=true;
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
            if( data[0]==1 && data[1]==2&& data[2]==3&& data[3]==4)
                super->onlineGame.conection=true;
        }
    }
}
void onlineGameClear(Engine* super){
}

