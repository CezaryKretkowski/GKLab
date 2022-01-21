//
// Created by cezar on 19.11.2021.
//

#ifndef GKLAB_PLAYER_H
#define GKLAB_PLAYER_H
#include "Tank.h"
#include "../Silnik/Point2D.h"
/**@class
 * Klas reprezętująca gracza
 */
class Player{
    ///Obiekt czołg
    Tank tank;
    ///Obiekt przechowujący wpółżędne
    Point2D missileCoords;
    ///Punkty dla poszczególnego gracza
    int points;
public:
    ///Konstuktor klay player
    Player();
    /**Metoda zwracjąca
     *
     * @return zwaraca liczbę punktow
     */
    int  getPoints();
    /**Metoda ustawiające liczbę punktów
     *
     * @param points nowa wartość punktów
     */
    void setPoints(int points);
    /**Metoda zwracjąca wskażnik czołg
     *
     * @return wskażnik na czolg
     */
    Tank* getTank(){return &tank;}
    /**Metoda zwaracająca
     *
     * @return wskażnika kordynaty pocisku
     */
    Point2D* getMissileCords(){return &missileCoords;}
    /**Metdoa uswiająca podstawowe parmatery gracza
     *
     * @param obstycle wskanik na listę przeszk od
     * @param skin ścierzka do pliku zwaierjacą obraz czołgu
     * @param missile ścierzka do pliku zwaierjacą obraz pocziku
     * @param up klawisz okdpowidzialny za ruch czolgu w górę
     * @param down klawisz okdpowidzialny za ruch czolgu w dół
     * @param left klawisz okdpowidzialny za ruch czolgu w lewo
     * @param right klawisz okdpowidzialny za ruch czolgu w praw
     * @param fire klawisz okdpowidzialny za strzelanie
     */
    void  setUpTank(std::vector<Obstycle>* obstycle,std::string skin,std::string missile,sf::Keyboard::Key up,sf::Keyboard::Key down,sf::Keyboard::Key left
    ,sf::Keyboard::Key right,sf::Keyboard::Key fire);
    /** Przeciążaona metoda ustwiąca podstawowe parametry gracza używana w trybie gry online
     *
     * @param pos obiekt reprezętujący pozycje pocisku
     * @param obstycle wskanik na listę przeszk od
     * @param skin ścierzka do pliku zwaierjacą obraz czołgu
     * @param missile ścierzka do pliku zwaierjacą obraz pocziku
     * @param up klawisz okdpowidzialny za ruch czolgu w górę
     * @param down klawisz okdpowidzialny za ruch czolgu w dół
     * @param left klawisz okdpowidzialny za ruch czolgu w lewo
     * @param right klawisz okdpowidzialny za ruch czolgu w praw
     * @param fire klawisz okdpowidzialny za strzelanie
     */
    void  setUpTank(Point2D pos,std::vector<Obstycle>* obstycle,std::string skin,std::string missile,sf::Keyboard::Key up,sf::Keyboard::Key down,sf::Keyboard::Key left
            ,sf::Keyboard::Key right,sf::Keyboard::Key fire);
    void setMissileCoords(){missileCoords.setX(0);missileCoords.setY(0);}
};
#endif //GKLAB_PLAYER_H
