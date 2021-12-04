//
// Created by cezar on 11.11.2021.
//
#include "Tank.h"
#include <iostream>
#include <cmath>
#include "PrimitiveRenderer.h"

#define PI 3.14159265

void setOriginAndReadjust(sf::Transformable &object, const sf::Vector2f &newOrigin) {
    auto offset = newOrigin - object.getOrigin();
    object.setOrigin(newOrigin);
    object.move(offset);
}

Tank::Tank(float posX, float posY, int angel) {
    this->posX = posX;
    this->posY = posY;
    this->angle = angel;
}

void Tank::setSkin(std::string path) {
    this->skin.loadFromFile(path);
    this->texture.loadFromImage(skin);
    this->painter.setTexture(texture);
}

void Tank::draw(sf::RenderWindow *parent) {
    painter.setPosition(this->posX, this->posY);


    setOriginAndReadjust(painter, ofset);
    parent->draw(painter);
    //std::cout<<painter.getRotation()<<std::endl;

}

void Tank::moveUp(sf::RenderWindow *parent) {
    sf::Color c = skin.getPixel(0, 0);
    if (sf::Keyboard::isKeyPressed(this->up)) {
        if (step > 20) {
            float rot = painter.getRotation();

            if (rot <= 90 && posY > 0 && posX < parent->getSize().x) {
                rot = 90.0 - rot;
                float a = sin(rot * PI / 180);
                float b = 1.0 - (a * a);
                float b1 = sqrt(b);
                if (checkCollision(parent, posX + b1, posY - a)) {

                    posY -= a;
                    posX += b1;
                }

            } else if (rot > 90 && rot <= 180 && posX < parent->getSize().x && posY < parent->getSize().y) {
                rot = rot - 90;
                float a = sin(rot * PI / 180);
                float b = 1 - (a * a);
                float b1 = sqrt(b);
                if (checkCollision(parent, posX + b1, posY + a)) {
                    posY += a;
                    posX += b1;
                }
            } else if (rot > 180 && rot <= 270 && posX > 0 && posY < parent->getSize().y) {
                rot = rot - 180;
                float a = sin(rot * PI / 180);
                float b = 1 - (a * a);
                float b1 = sqrt(b);
                if (checkCollision(parent, posX - a, posY + b1)) {
                    posY += b1;
                    posX -= a;
                }
            } else if (rot > 270 && rot <= 360 && posX > 0 && posY > 0) {
                rot = rot - 270;
                float a = sin(rot * PI / 180);
                float b = 1 - (a * a);
                float b1 = sqrt(b);
                if (checkCollision(parent, posX - b1, posY - a)) {
                    posY -= a;
                    posX -= b1;
                }
            }
            step = 0;
        }
        step++;

    }
}

void Tank::moveDown(sf::RenderWindow *parent) {

    if (sf::Keyboard::isKeyPressed(this->down)) {
        if (step > 20) {
            float rot = painter.getRotation();

            if (rot <= 90 && posX > 0 && posY < parent->getSize().y) {//posX > 0 && posY < parent->getSize().y
                rot = 90.0 - rot;
                float a = sin(rot * PI / 180);
                float b = 1.0 - (a * a);
                float b1 = sqrt(b);
                if (checkCollision(parent, posX - b1, posY + a)) {
                    posY += a;
                    posX -= b1;
                }
                // std::cout << "pos" << posY << std::endl;
            } else if (rot > 90 && rot <= 180 && posX > 0 && posY > 0) {//rot <= 360 && posX > 0 && posY > 0
                rot = rot - 90;
                float a = sin(rot * PI / 180);
                float b = 1 - (a * a);
                float b1 = sqrt(b);
                if (checkCollision(parent, posX - b1, posY - a)) {
                    posY -= a;
                    posX -= b1;
                }
            } else if (rot > 180 && rot <= 270 && posY > 0 &&
                       posX < parent->getSize().x) {//posY > 0 && posX < parent->getSize().x
                rot = rot - 180;
                float a = sin(rot * PI / 180);
                float b = 1 - (a * a);
                float b1 = sqrt(b);
                if(checkCollision(parent,posX +a,posY-b1)) {
                    posY -= b1;
                    posX += a;
                }
            } else if (rot > 270 && rot <= 360 && posX < parent->getSize().x &&
                       posY < parent->getSize().y) {//posX < parent->getSize().x && posY < parent->getSize().y
                rot = rot - 270;
                float a = sin(rot * PI / 180);
                float b = 1 - (a * a);
                float b1 = sqrt(b);
                if(checkCollision(parent,posX +b1,posY+a)) {
                    posY += a;
                    posX += b1;
                }
            }
            step = 0;
        }
        step++;

    }


}

void Tank::rotLeft(sf::RenderWindow *parent) {
    int i = 0;
    if (sf::Keyboard::isKeyPressed(this->left)) {
        angle++;
        if (angle == 50) {
            i++;
            painter.rotate(0);
            painter.rotate(i);

            angle = 0;
        }
    }

}

void Tank::rotRight(sf::RenderWindow *parent) {
    int i = 0;
    if (sf::Keyboard::isKeyPressed(this->right)) {
        angle++;
        if (angle == 50) {
            i--;
            painter.rotate(0);
            painter.rotate(i);

            angle = 0;
        }
    }

}

void Tank::fireFun(sf::RenderWindow *parent) {
    if (sf::Keyboard::isKeyPressed(this->fire) && (loading != true)) {
        loading = true;
        ms.setPosX(posX);
        ms.setPosY(posY);

        float rot = painter.getRotation();
        ms.setRot(rot);
    }


}

void Tank::drawMissile(sf::RenderWindow *parent,sf::Clock* cl,Point2D *msille) {
    float y = ms.getY();
    float x = ms.getX();


    int i = ms.getCount();

    if (loading && i < 300) {
        cl->restart();
        float rot = ms.getRot();
        if (rot <= 90 && y > 0 && x < parent->getSize().x) {
            rot = 90.0 - rot;
            float a = sin(rot * PI / 180);
            float b = 1.0 - (a * a);
            float b1 = sqrt(b);
            if (checkCollision(parent, x +b1, y - a)) {
                y -= a;
                x += b1;
            }else{
                i=300;
                ms.setCount(i);
                cl->restart();
            }
        } else if (rot > 90 && rot <= 180 && x < parent->getSize().x && y < parent->getSize().y) {
            rot = rot - 90;
            float a = sin(rot * PI / 180);
            float b = 1 - (a * a);
            float b1 = sqrt(b);
            if (checkCollision(parent, x +b1, y + a)) {
                y += a;
                x += b1;
            }else
            {
                i=300;
                ms.setCount(i);
                cl->restart();
            }
        } else if (rot > 180 && rot <= 270 && x > 0 && y < parent->getSize().y) {
            rot = rot - 180;
            float a = sin(rot * PI / 180);
            float b = 1 - (a * a);
            float b1 = sqrt(b);
            if (checkCollision(parent, x - a, y + b1)) {
                y += b1;
                x -= a;
            }else{
                i=300;
                ms.setCount(i);
                cl->restart();
            }
        } else if (rot > 270 && rot <= 360 && x > 0 && y > 0) {
            rot = rot - 270;
            float a = sin(rot * PI / 180);
            float b = 1 - (a * a);
            float b1 = sqrt(b);
            if (checkCollision(parent, x - b1, y - a)) {
                y -= a;
                x -= b1;
            }else{
                i=300;
                ms.setCount(i);
                cl->restart();
            }

        }
        ms.setPosY(y);
        ms.setPosX(x);
        msille->setX(x);
        msille->setY(y);

        ms.draw(parent);
        i++;


        ms.setCount(i);


    }
    float t=cl->getElapsedTime().asSeconds();

    if (t>3) {
        ms.setCount(0);
        this->loading = false;
    }
    step1 = 0;


}

bool Tank::checkCollision(sf::RenderWindow *super, double x, double y) {
    bool detected=true;
    i = obstycleList->begin();

     for(i;i!=obstycleList->end();i++) {
         float x0 = i->getPosX();
         float x1 = i->getImage().getSize().x + x0;
         float y0 = i->getPosY();
         float y1 = i->getImage().getSize().y + y0;

         if (x >= x0 && x <= x1 && y >= y0 && y <= y1)
             detected = false;
     }

    return detected;
}
bool Tank::checkHit(Point2D *p,int n) {
    bool check=false;
    float x0=posX;
    float  x1=posX+skin.getSize().x;
    float  y0=posY;
    float  y1=posY+skin.getSize().x;


    if(p->getX()>=x0&& p->getX() <= x1 && p->getY() >= y0 && p->getY() <= y1){
       hit++;


    }else
        hit=0;
    if(hit==1)
        check=true;


    return check;
}
