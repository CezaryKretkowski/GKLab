//
// Created by cezar on 28.12.2021.
//

#ifndef SERVER_CLIENTSERVER_H
#define SERVER_CLIENTSERVER_H
#include <SFML/Network.hpp>
/**@class  ClientServer Kalsa odpowiedzialna za grą online */
class ClientServer{
public:
    //ClientServer(unsigned short =5000);
    ///Tablica typu float która jest wykorzystywana jako buffor na dane
    float buffer[7];
    ///Zmienna przchowująca numer portu
    unsigned short port;
    ///Zmienna określająca role hosta
    bool serverRole;
    ///Zmienna określająca adress ip
    sf::IpAddress  recipient="localhost";
    ///Gnizado sieciowe udp wykorzystywane do połącznia
    sf::UdpSocket socket;
    ///Metoda ta przypisuje w gnieździe adres protokołu lokalnego w celu pobierania danych
    ///@return Zwraca prawdę jeśli w metoda została poprawnie wykonana albo fałsz w przciwnym wypadku
    bool Bind();
    /**Metoda służąca do wysłania testowego ciągu liczb aby sprawdzić połączenie
     *
     * @param tankPosX Pozycja x czołgu
     * @param tankPosY Pozycja Y czołgu
     * @param bulletPosX Pozycja pocisku X
     * @param bulletPosY Pozycja pocisku Y
     * @return Zwraca prawdę jeśli w metoda została poprawnie wykonana albo fałsz w przciwnym wypadku
     */
    bool SendPos(float tankPosX,float tankPosY,float bulletPosX,float bulletPosY);
    /**Przeciążona metoda służaca do wysyłania dancyh okreśłających pozycje przciwnika
     *
     * @param tankPosX Pozycja x czołgu
     * @param tankPosY Pozycja Y czołgu
     * @param rotTank kąt pod jakim jest obrócony czołg przeciwnika
     * @param bulletPosX Pozycja pocisku X
     * @param bulletPosY Pozycja pocisku y
     * @param rotMissile kąt pod jakim jest obrócony pocisk
     * @param fire zmienna określająca czs przeładowania przeciwnika
     * @return Zwraca prawdę jeśli w metoda została poprawnie wykonana albo fałsz w przciwnym wypadku
     */
    bool SendPos(float tankPosX,float tankPosY,float rotTank,float bulletPosX,float bulletPosY,float rotMissile,float fire);
    ///Metoda służaca do odbierania pakietu danych
    bool Receive(float data[7]);
};
#endif //SERVER_CLIENTSERVER_H
