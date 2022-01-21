//
// Created by cezar on 30.12.2021.
//

#ifndef GKLAB_ONLINEGAMEVIEW_H
#define GKLAB_ONLINEGAMEVIEW_H
#include "../Obstycle.h"
#include <vector>
#include "../Player.h"
#include "../Label.h"
#include "../Button.h"
#include "../Button.h"
#include "../SinglPlayerGame/Pause.h"
#include "../../Silnik/BitmapHandler.h"
#include "../EndGame.h"
#include "ConectingScreen.h"
#include "ClientServer.h"
///@class Zawierajca pola i metody do obsługi trybu online
class OnlineGameView{
private:
    ///Obiekt pierwszego gracza
    Player player1;
    ///Obiekt drugiego gracza
    Player player2;
    ///Lista przeszkód na mapie
    std::vector<Obstycle> obstycle;
    ///Obiekt przechowujący i wyświetlający aktualny wynik
    Label wynik;
public :
    ///Obiekt służący do utworzenia gry online
    ClientServer networkClass;
    ///zmienna określając czy jesteśmy połączenie
    bool conection=false;
    ///Obiket reprzętujący widok umożliwający stworzenie gry online
    ConectingScreen scren;
    ///Obiekt przechowującę tło
    BitmapHandler background;
    /**Metoda zwracająca gracza jeden
     *
     * @return wskażnik na pierwszego gracza
     */
    Player* getPlayer1(){return &player1;};
    /**Metoda zwracająca gracza dwa
     *
     * @return wskażnik na drugiego gracza
     */
    Player* getPlayer2(){return &player2;};
    ///Lista przeszkód
    std::vector<Obstycle>* getObtycleList();
    /**Metoda służacca do wyświetlania listy przeszkód
    *
    * @param parent wskażnik na okno główne
    */
    void drawObstycles(sf::RenderWindow *parent);
    /**Metoda zwracająca
     *
     * @return wskażnik na polę nagłówka
     */
    Label* getLabel(){return &wynik;};
    /**Metoda służaca do dania nowych przeszkód do listy
     *
     * @param o Nowa przeszkoda
     */
    void addObstycle(Obstycle o);

};
#endif //GKLAB_ONLINEGAMEVIEW_H
