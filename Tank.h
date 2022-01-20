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
#include "Point2D.h"
#include <list>

class Tank{
    /**Klasa reperezentująca obiekt Tank
     **/
private:
    sf::Image skin;  /// Obiekt przchowujący obraz czołgu
    sf::Texture texture; /// Obiekt preczhuwjący txture czolu
    std::string skinName;/// ścieżka do pliku img z obrazem czołgu
    float posX;/// wpólżędna x pozycji czolgu
    float posY;/// wpólżędna y pozycji czolgu
    int angle;/// kąt odchylenia czolgu
    sf::Keyboard::Key up;/// Klawisz odpowiedzialny za ruch czolgu w górę
    sf::Keyboard::Key down;/// Klawisz odpowiedzialny za ruch czolgu w dół
    sf::Keyboard::Key left;/// Klawisz odpowiedzialny za ruch czolgu w lewo
    sf::Keyboard::Key right;/// Klawisz odpowiedzialny za ruch czolgu w prawo
    sf::Keyboard::Key fire;/// Klawisz odpowiedzialny za odawanie strzału
    sf::Sprite painter;/// Obiekt służący do wyrysowania czoług na ekranie
    std::vector<Obstycle>::iterator i;/// lista zwierające wspolżedne przeszkud na mapie
    int step=0;/// zmienna wykorzystana do generowania opużnienia w poruszaniu się czolgu
    int step1=0;
    Missile ms;/// obiek reprezętujący pocisk
    bool loading=false;/// zmienna wykorzystywana do zasyuowania przeładowania
    int hit;/// zmienna wykorzystywan a do detekcji trafienia
    std::list<sf::Image> fiereImg;
    sf::Music sound;///Obiekt słuzaćy do wyświetlnie muzyki

public:
    ///Metoda służąca do pobierania rozmianu czołgu
    sf::Vector2u getSize(){
        return  skin.getSize();
    }
    ///Metoda zwracająca wartość
    bool getLoad(){return loading;}

    std::string getSkin(){return skinName;}
    std::vector<Obstycle>* obstycleList;
    sf::Vector2f ofset;
    Tank(float =100.0,float =100.0,int=0);
    void  setPosX(float x){this->posX=x;};
    void  setPosY(float y){this->posY=y;};
    void setAngel(int angel){angle=angle;
    painter.setRotation(angel);};
    float getPosX(){return posX;}
    float getPosY(){return posY;}
    float getAngle(){return painter.getRotation();}
    sf::Keyboard::Key getUpKey(){return up;}
    sf::Keyboard::Key getDownKey(){return down;}
    sf::Keyboard::Key getRightKey(){return right;}
    sf::Keyboard::Key getLeftKey(){return left;}
    sf::Keyboard::Key getFireKey(){return fire;}
    void setUpKey(sf::Keyboard::Key k){up=k;}
    void setDownKey(sf::Keyboard::Key k){down=k;}
    void setLeftKey(sf::Keyboard::Key k){left=k;}
    void setRightKey(sf::Keyboard::Key k){right=k;}
    void setFireKey(sf::Keyboard::Key k){fire=k;}
    void setSkin(std::string path);
    void draw(sf::RenderWindow *parent);
    void moveUp(sf::RenderWindow *parent);
    void moveDown(sf::RenderWindow *parent);
    void rotLeft(sf::RenderWindow *parent);
    void rotRight(sf::RenderWindow *parent);
    void fireFun(sf::RenderWindow *parent);
    void fireFun(sf::RenderWindow *parent,int condytion);
    Missile* getMissile(){return &ms;};
    void drawMissile(sf::RenderWindow *parent,sf::Clock* cl,Point2D *msille);
    bool checkCollision(sf::RenderWindow* super,double x,double y);
    bool checkHit(Point2D* p,int n);
    void drawFire(sf::RenderWindow *parent,sf::Clock* cl);
    void addFireImg(std::string path);
    void loadExsploutionSound(std::string path);
    bool checkHit(Point2D *p,float load) ;
};
#endif //GKLAB_TANK_H
