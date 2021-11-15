//
// Created by cezar on 11.11.2021.
//
#include "Tank.h"
#include <iostream>
#include <cmath>
#include "PrimitiveRenderer.h"
#define PI 3.14159265
void setOriginAndReadjust(sf::Transformable &object, const sf::Vector2f &newOrigin)
{
    auto offset = newOrigin - object.getOrigin();
    object.setOrigin(newOrigin);
    object.move(offset);
}
Tank::Tank(float posX, float posY, int angel) {
    this->posX=posX;
    this->posY=posY;
    this->angle=angel;
}
void Tank::setSkin(std::string path) {
    this->skin.loadFromFile(path);
    this->texture.loadFromImage(skin);
    this->painter.setTexture(texture);
}
void Tank::draw(sf::RenderWindow *parent) {
    painter.setPosition(this->posX, this->posY);


    setOriginAndReadjust(painter,ofset);
    parent->draw(painter);
    std::cout<<painter.getRotation()<<std::endl;

}
void Tank::moveUp(sf::RenderWindow *parent) {

    if(sf::Keyboard::isKeyPressed(this->up)){
        if(step>50) {
            float rot = painter.getRotation();

            if (rot <= 90 && posY > 0 && posX < parent->getSize().x) {
                rot = 90.0 - rot;
                float a = sin(rot * PI / 180);
                float b = 1.0 - (a * a);
                float b1 = sqrt(b);
                posY -= a;
                posX += b1;
                std::cout << "pos" << posY << std::endl;
            } else if (rot > 90 && rot <= 180 && posX < parent->getSize().x && posY < parent->getSize().y) {
                rot = rot - 90;
                float a = sin(rot * PI / 180);
                float b = 1 - (a * a);
                float b1 = sqrt(b);
                posY += a;
                posX += b1;
            } else if (rot > 180 && rot <= 270 && posX > 0 && posY < parent->getSize().y) {
                rot = rot - 180;
                float a = sin(rot * PI / 180);
                float b = 1 - (a * a);
                float b1 = sqrt(b);
                posY += b1;
                posX -= a;
            } else if (rot > 270 && rot <= 360 && posX > 0 && posY > 0) {
                rot = rot - 270;
                float a = sin(rot * PI / 180);
                float b = 1 - (a * a);
                float b1 = sqrt(b);
                posY -= a;
                posX -= b1;
            }
            step=0;
        }
        step++;

    }
}
void Tank::moveDown(sf::RenderWindow *parent) {

    if(sf::Keyboard::isKeyPressed(this->down)){
        if(step>50) {
            float rot = painter.getRotation();

            if (rot <= 90 && posX > 0 && posY < parent->getSize().y) {//posX > 0 && posY < parent->getSize().y
                rot = 90.0 - rot;
                float a = sin(rot * PI / 180);
                float b = 1.0 - (a * a);
                float b1 = sqrt(b);
                posY += a;
                posX -= b1;
                std::cout << "pos" << posY << std::endl;
            } else if (rot > 90 && rot <= 180 && posX > 0 && posY > 0) {//rot <= 360 && posX > 0 && posY > 0
                rot = rot - 90;
                float a = sin(rot * PI / 180);
                float b = 1 - (a * a);
                float b1 = sqrt(b);
                posY -= a;
                posX -= b1;
            } else if (rot > 180 && rot <= 270 && posY > 0 && posX < parent->getSize().x) {//posY > 0 && posX < parent->getSize().x
                rot = rot - 180;
                float a = sin(rot * PI / 180);
                float b = 1 - (a * a);
                float b1 = sqrt(b);
                posY -= b1;
                posX += a;
            } else if (rot > 270 && rot <= 360 && posX < parent->getSize().x && posY < parent->getSize().y) {//posX < parent->getSize().x && posY < parent->getSize().y
                rot = rot - 270;
                float a = sin(rot * PI / 180);
                float b = 1 - (a * a);
                float b1 = sqrt(b);
                posY += a;
                posX += b1;
            }
            step=0;
        }
        step++;

    }


}
void Tank::rotLeft(sf::RenderWindow *parent) {
    int i=0;
    if(sf::Keyboard::isKeyPressed(this->left)){
        angle++;
        if(angle==50){
            i++;
        painter.rotate(0);
        painter.rotate(i);

            angle=0;
        }
    }

}
void Tank::rotRight(sf::RenderWindow *parent) {
    int i=0;
    if(sf::Keyboard::isKeyPressed(this->right)){
        angle++;
        if(angle==50){
            i--;
            painter.rotate(0);
            painter.rotate(i);

            angle=0;
        }
    }

}
void Tank::fireFun(sf::RenderWindow *parent) {
     if(sf::Keyboard::isKeyPressed(this->fire)&&(loading!=true)){
         loading=true;
        ms.setPosX(posX);
        ms.setPosY(posY);

        float rot=painter.getRotation();
        ms.setRot(rot);
    }


}
void Tank::drawMissile(sf::RenderWindow *parent) {
    float y=ms.getY();
    float x=ms.getX();

    int i=ms.getCount();

        if (loading && i < 300) {

               float rot = ms.getRot();
               if (rot <= 90 && y > 0 && x < parent->getSize().x) {
                   rot = 90.0 - rot;
                   float a = sin(rot * PI / 180);
                   float b = 1.0 - (a * a);
                   float b1 = sqrt(b);
                   y -= a;
                   x += b1;

               } else if (rot > 90 && rot <= 180 && x < parent->getSize().x && y < parent->getSize().y) {
                   rot = rot - 90;
                   float a = sin(rot * PI / 180);
                   float b = 1 - (a * a);
                   float b1 = sqrt(b);
                   y += a;
                   x += b1;
               } else if (rot > 180 && rot <= 270 && x > 0 && y < parent->getSize().y) {
                   rot = rot - 180;
                   float a = sin(rot * PI / 180);
                   float b = 1 - (a * a);
                   float b1 = sqrt(b);
                   y += b1;
                   x -= a;
               } else if (rot > 270 && rot <= 360 && x > 0 && y > 0) {
                   rot = rot - 270;
                   float a = sin(rot * PI / 180);
                   float b = 1 - (a * a);
                   float b1 = sqrt(b);
                   y -= a;
                   x -= b1;
               }
               ms.setPosY(y);
               ms.setPosX(x);

               ms.draw(parent);
               for(int j=0;j<300;j++){}
               i++;




               ms.setCount(i);




        }
        if (i == 299) {
            ms.setCount(0);
            this->loading = false;
        }
        step1=0;


}
