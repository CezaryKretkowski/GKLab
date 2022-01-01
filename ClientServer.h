//
// Created by cezar on 28.12.2021.
//

#ifndef SERVER_CLIENTSERVER_H
#define SERVER_CLIENTSERVER_H
#include <SFML/Network.hpp>
class ClientServer{
public:
    //ClientServer(unsigned short =5000);

    unsigned short port;
    bool serverRole;
    sf::IpAddress  recipient="localhost";
    sf::UdpSocket socket;
    bool Bind();
    bool SendPos(float tankPosX,float tankPosY,float bulletPosX,float bulletPosY);
    bool Receive(float data[4]);
};
#endif //SERVER_CLIENTSERVER_H
