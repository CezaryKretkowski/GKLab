//
// Created by cezar on 28.12.2021.
//
#include "ClientServer.h"
#include <iostream>

bool ClientServer::Bind() {
    bool connected=true;

    if(socket.bind(port)!=sf::Socket::Done)
        connected=false;

    return connected;
}
bool ClientServer::SendPos(float tankPosX, float tankPosY, float bulletPosX, float bulletPosY) {
    bool check=true;

    float data[]={tankPosX,tankPosY,bulletPosX,bulletPosY};
    if(socket.send(data,sizeof data,recipient,port)!=sf::Socket::Done)
        check=false;
   // std::cout<<"Wiadomość zostal wysłana poporawnie na port :"<<sendPort<<std::endl;
    return check;
}
bool ClientServer::Receive(float data[]) {
    bool check=true;
    std::size_t received;
    sf::IpAddress sender;
    unsigned short SenderPort;

    if(socket.receive(data, 100, received, sender, SenderPort)!=sf::Socket::Done){
        check=false;
    }
    port=SenderPort;
   // std::cout << "Received " << received << " bytes from " << this->recipient << " on port " << SenderPort<<"Port do nasłuchu " << recivePort<<std::endl;
    return check;
}
