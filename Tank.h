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
private:
    sf::Image skin;
    sf::Texture texture;
    std::string skinName;
    float posX;
    float posY;
    int angle;
    sf::Keyboard::Key up;
    sf::Keyboard::Key down;
    sf::Keyboard::Key left;
    sf::Keyboard::Key right;
    sf::Keyboard::Key fire;
    sf::Sprite painter;
    std::vector<Obstycle>::iterator i;
    int step=0;
    int step1=0;
    Missile ms;
    bool loading=false;
    int hit;
    std::list<sf::Image> fiereImg;

public:
    sf::Vector2u getSize(){
        return  skin.getSize();
    }
    std::string getSkin(){return skinName;}
    std::vector<Obstycle>* obstycleList;
    sf::Vector2f ofset;
    Tank(float =100.0,float =100.0,int=0);
    void  setPosX(float x){this->posX=x;};
    void  setPosY(float y){this->posY=y;};
    void setAngel(int angel){angle=angle;};
    float getPosX(){return posX;}
    float getPosY(){return posY;}
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
    Missile* getMissile(){return &ms;};
    void drawMissile(sf::RenderWindow *parent,sf::Clock* cl,Point2D *msille);
    bool checkCollision(sf::RenderWindow* super,double x,double y);
    bool checkHit(Point2D* p,int n);
    void drawFire(sf::RenderWindow *parent,sf::Clock* cl);
    void addFireImg(std::string path);
    void loadExsploutionSound(std::string path);
};
#endif //GKLAB_TANK_H