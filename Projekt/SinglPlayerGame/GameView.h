//
// Created by cezar on 11.11.2021.
//

#ifndef GKLAB_GAMEVIEW_H
#define GKLAB_GAMEVIEW_H

#include "../Tank.h"
#include <SFML/Graphics.hpp>
#include "../Obstycle.h"
#include <vector>
#include "../Player.h"
#include "../Label.h"
#include <list>
#include "../Button.h"
#include "Pause.h"
#include "../../Silnik/BitmapHandler.h"
#include "../EndGame.h"

/**@class Klasa opisująca główny tryb gry*/
class GameView {
private:
    ///Obiekt pierwszego gracza
    Player player1;
    ///Obiekt pierwszego gracza
    Player player2;
    ///Lista przeszkód na mapie
    std::vector<Obstycle> obstycle;
    ///Obiekt przechowujący i wyświetlający aktualny wynik
    Label wynik;
    ///Falga określajac czy rozgrywka ma zostać wpisana z pliku tekstowego
    bool load;
    ///Flaga służaca do wyświetlneia pouzy w czasie rozgrywki
    bool pause = false;
    ///Flaga określajća czy klawisz odpowiedzialny za wciśnięcie pauzy został wykryty
    bool keyPressed = false;
public:
    ///Obiekt przechowujący tło
    BitmapHandler background;
    ///Obiekt odpowiedzialny za wyswietlanie menu
    Pause pauseMenu;
    ///Obiekt odpowiedzialny za wyświetlanie końcowych wyników gry
    EndGame endGame;

    /**Metoda ustawiająca
     *
     * @param load  ustawienia flagi która określa wczytanie rozgrywki
     */
    void setLoad(bool load) { this->load = load; }
    /**Metoda zwracająca
     *
     * @return flag odpowiedzialną za wczytywanie gry
     */
    bool getLoad() { return load; }
    /**Metoda zwracająca
     *
     * @return wskażnik na polę nagłówka
     */

    Label *getLabel() { return &wynik; };
    /**Metoda służaca do dania nowych przeszkód do listy
     *
     * @param o Nowa przeszkoda
     */
    void addObstycle(Obstycle o);

    Obstycle getObstycle(int index);

    //Obstycle testeing;
    /**Metoda zwracająca gracza jeden
     *
     * @return wskażnik na pierwszego gracza
     */
    Player *getPlayer1() { return &player1; };
    /**Metoda zwracająca gracza dwa
     *
     * @return wskażnik na drugiego gracza
     */
    Player *getPlayer2() { return &player2; };

    void setPixelMap();

    int getPiksel(int x, int y);
    /**Metoda liste przeszkód
    *
    * @return wskażnik na listę przeszkód
    */
    std::vector<Obstycle> *getObtycleList();
    /**Metoda służacca do wyświetlania listy przeszkód
     *
     * @param parent wskażnik na okno główne
     */
    void drawObstycles(sf::RenderWindow *parent);
    /**Metoda Odpowiedzialna za obsługę klawisz pauzy
     */
    void pauseKey();
    /**Metoda zwracjąca stan falgi pauzy
     *
     * @return wartość zmienne boolowskie pauza
     */
    bool getPasue() { return pause; }

    /**Metoda Ustawiająca
    *
    * @param pause Obiekt odpowiedzialny za wyświetlanie pauzy
    */
    void setPasue(bool pause) { this->pause = pause; }
    /**Metoda odpowiedzialna za zapis gry
     *
     * @param p1Pos pozycja gracza 1
     * @param p2Pos pozycja gracza 1
     * @param skin1 ścieżka do obrazu pierwszego czołgu
     * @param skin2 ścieżka do obrazu drugiego czołgu
     * @param obs lista przeszkód
     * @param Point1 liczab punktów pierwszego gracza
     * @param Point2 liczab punktów drugiego gracza
     */
    void saveToFile(Point2D p1Pos, Point2D p2Pos, std::string skin1, std::string skin2, std::vector<Obstycle> *obs,
                    int Point1, int Point2);
    /**Metoda służaca do wczytania danych z pliku
     * */
    void loadFromFile();
};

#endif //GKLAB_GAMEVIEW_H
