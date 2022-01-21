//
// Created by cezar on 11.11.2021.
//

#ifndef GKLAB_TANK_H
#define GKLAB_TANK_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//#include <SFML/Sound.hpp>
#include "Missile.h"
#include <iostream>
#include "Obstycle.h"
#include "../Silnik/Point2D.h"
#include <list>

/** @class Klasa reperezentująca obiekt Tank
     **/
class Tank {

private:
    /// Obiekt przchowujący obraz czołgu
    sf::Image skin;
    /// Obiekt preczhuwjący txture czolu
    sf::Texture texture;
    /// ścieżka do pliku img z obrazem czołgu
    std::string skinName;
    /// wpólżędna x pozycji czolgu
    float posX;
    /// wpólżędna y pozycji czolgu
    float posY;
    /// kąt odchylenia czolgu
    int angle;
    /// Klawisz odpowiedzialny za ruch czolgu w górę
    sf::Keyboard::Key up;
    /// Klawisz odpowiedzialny za ruch czolgu w dół
    sf::Keyboard::Key down;
    /// Klawisz odpowiedzialny za ruch czolgu w lewo
    sf::Keyboard::Key left;
    /// Klawisz odpowiedzialny za ruch czolgu w prawo
    sf::Keyboard::Key right;
    /// Klawisz odpowiedzialny za odawanie strzału
    sf::Keyboard::Key fire;
    /// Obiekt służący do wyrysowania czoług na ekranie
    sf::Sprite painter;
    /// iterator listy zwierającej wspolżedne przeszkud na mapie
    std::vector<Obstycle>::iterator i;
    /// zmienna wykorzystana do generowania opużnienia w poruszaniu się czolgu
    int step = 0;
    int step1 = 0;
    /// obiek reprezętujący pocisk
    Missile ms;
    /// zmienna wykorzystywana do zasyuowania przeładowania
    bool loading = false;
    /// zmienna wykorzystywan a do detekcji trafienia
    int hit;
    std::list<sf::Image> fiereImg;
    ///Obiekt słuzaćy do wyświetlnie muzyki
    sf::Music sound;

public:
    ///Metoda służąca do pobierania rozmianu czołgu
    sf::Vector2u getSize() {
        return skin.getSize();
    }

    ///Metoda zwracająca wartość
    ///@return zwarca warotość określjąca czy dany czołg jest gorowy do strzało
    bool getLoad() { return loading; }

    ///@reurn zwraca obiekt skin
    std::string getSkin() { return skinName; }

    ///Lista przeszkód
    std::vector<Obstycle> *obstycleList;

    /// Presunieciu środka "sprite'u"
    sf::Vector2f ofset;

    /** Konstuktor klasy tank
     * @param posx parametr okręlsający wpólżędną x
     * @param posy parametr okręlsający wpólżędną y
     * @param angle parametr okręlsający kąt
     */
    Tank(float = 100.0, float = 100.0, int = 0);

    /**Metoda ustaiająca pozycje  wpólżędną x
     *
     * @param x wspólżedna określająca nowa wartość wpsolżędnej x
     */
    void setPosX(float x) { this->posX = x; };

    /**Metoda ustaiająca pozycje  wpólżędną y
     *
     * @param y nowa wspołżędna y
     */
    void setPosY(float y) { this->posY = y; };

    /**Metoda ustaiająca kąt  **/
    void setAngel(int angel) {
        angle = angle;
        painter.setRotation(angel);
    };

    /**Metoda zwracjąca pozycje  wpólżędną x
     *
     * @return  wartoś wpołędzne x
     */
    float getPosX() { return posX; }

    /**Metoda zwaracjąca  pozycje  wpólżędną y
     *
     * @return zwaraca wrtośc wpolżdene y
     */
    float getPosY() { return posY; }

    /**Metoda zwarcjąca kąt
     *
     * @return zwaraca wrtosć kąta
     */
    float getAngle() { return painter.getRotation(); }

    /**Metoda zwarcjąca
    *
    * @return klawisz odpowiedzialny za ruch w górę
    */
    sf::Keyboard::Key getUpKey() { return up; }

    /**Metoda zwarcjąca
    *
    * @return klawisz określający ruch w dól
    */
    sf::Keyboard::Key getDownKey() { return down; }

    /**Metoda zwarcjąca
    *
    * @return klawisz określający ruch w parwo
1    */
    sf::Keyboard::Key getRightKey() { return right; }
    /**Metoda zwarcjąca
   *
   * @return klawisz określający ruch w lewo
   */
    sf::Keyboard::Key getLeftKey() { return left; }
    /**Metoda zwarcjąca
    *
    * @return  klawisz określający strzał
    */
    sf::Keyboard::Key getFireKey() { return fire; }
    /**Metoda Ustawiająca
    *
    * @param k nowy kalwisz odpowiedzialny ruch w górę
    */
    void setUpKey(sf::Keyboard::Key k) { up = k; }
    /**Metoda zwarcjąca
    *
    * @param k ustawia nowy klawisz odpowiedzialny za ruch w prawo
    */
    void setDownKey(sf::Keyboard::Key k) { down = k; }
    /**Metoda ustawiająca
    *
    * @param k ustawia nowy klawisz odpowiedzialny za ruch w lewo
    */
    void setLeftKey(sf::Keyboard::Key k) { left = k; }
    /**Metoda ustawiająca
    *
    * @param k ustawia nowy klawisz odpowiedzialny za ruch w prawo
    */
    void setRightKey(sf::Keyboard::Key k) { right = k; }
    /**Metoda ustawiająca
    *
    * @param k k ustawia nowy klawisz odpowiedzialny za strzał
    */
    void setFireKey(sf::Keyboard::Key k) { fire = k; }
    /**Metoda ustawiająca
    *
    * @param path parametr określający ścieżkę do pliku z obarzem czołgu
    */
    void setSkin(std::string path);
    /**Metoda służąca do wyświetlania czołgu na ekranie
    *
    * @param parent Wskażnik na okno gry
    */
    void draw(sf::RenderWindow *parent);
    /**  Metoda odpowiedzialna z aobsługę ruch czołgu w góre
     *
     * @param parent
     */
    void moveUp(sf::RenderWindow *parent);
    /**Metoda odpowiedzialna z aobsługę ruch czołgu w dół
     *
     * @param parent  Wskażnik na okno gry
     */
    void moveDown(sf::RenderWindow *parent);
    /**Metoda odpowiedzialna z aobsługę rotacji czołgu w lewo
     *
     * @param parent  Wskażnik na okno gry
     */
    void rotLeft(sf::RenderWindow *parent);
    /**Metoda odpowiedzialna z aobsługę rotacji czołgu w prawo
     *
     * @param parent  Wskażnik na okno gry
     */
    void rotRight(sf::RenderWindow *parent);
    /**Metoda odpowiedzialna z aobsługę strzału
     *
     * @param parent  Wskażnik na okno gry
     */
    void fireFun(sf::RenderWindow *parent);
    /**
     *
     * @param parent  Wskażnik na okno gry
     * @param condytion zmienna okrślająca warunek wykonnania strzzłu
     */
    void fireFun(sf::RenderWindow *parent, int condytion);
    /** Metoda zwaracjąca
     *
     * @return zwraca wskaźniek na obiekt pocisku
     */
    Missile *getMissile() { return &ms; };
    /** Metoda służąca do wyświelania pocisku
     *
     * @param parent Wskażnik na okno gry
     * @param cl Wskażnik na zegar
     * @param msille Wskażnik na pocisk
     */
    void drawMissile(sf::RenderWindow *parent, sf::Clock *cl, Point2D *msille);
    /**Metoda służaća do detekcji kolizji
     *
     * @param super Wskażnik na okno gry
     * @param x wspułżędna X
     * @param y wspułżędna Y
     * @return Prawdę jesśli wykryto kolizję z jakąś przeszkodą lub fałsz w przeciwnym wypadku
     */
    bool checkCollision(sf::RenderWindow *super, double x, double y);
    /** Zmienna służaća do detekcji trafień
     *
     * @param p wspołżðene pocisku
     * @return zwraca prawdę jeśli zostało wykreyte trafienie i fałsz w przciwnym przypadku
     */
    bool checkHit(Point2D *p, int n);

    void drawFire(sf::RenderWindow *parent, sf::Clock *cl);

    void addFireImg(std::string path);
    /** Metoda służaca do wczytywania ścieżki dziękowej odwarzanej pod czas strzału
     *
     * @param path ścieżkę do pliku dzwiękowego
     */
    void loadExsploutionSound(std::string path);

    bool checkHit(Point2D *p, float load);
};

#endif //GKLAB_TANK_H
