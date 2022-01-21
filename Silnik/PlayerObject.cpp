//
// Created by cezar on 25.11.2021.
//
#include "PlayerObject.h"
#include <iostream>
void PlayerObject::moveUp(sf::RenderWindow *super) {
    if(sf::Keyboard::isKeyPressed(up)&&!sf::Keyboard::isKeyPressed(down)&&!sf::Keyboard::isKeyPressed(left)&&!sf::Keyboard::isKeyPressed(right)){
        mainIterator++;

        if(mainIterator==100) {
            //super->clear();
            upAnymation.setPosX(posX);
            upAnymation.setPosY(posY);
            posY -= 1;

            upAnymation.animate(super, true);
            mainIterator = 0;
        }
        upAnymation.draw(super);
    }



}

void PlayerObject::moveDown(sf::RenderWindow *super) {
    if(!sf::Keyboard::isKeyPressed(up)&&sf::Keyboard::isKeyPressed(down)&&!sf::Keyboard::isKeyPressed(left)&&!sf::Keyboard::isKeyPressed(right)){
        mainIterator++;

        if(mainIterator==100) {
            //super->clear();
            downAnymation.setPosX(posX);
            downAnymation.setPosY(posY);
            posY += 1;

            downAnymation.animate(super, true);
            mainIterator=0;
        }
        downAnymation.draw(super);
    }


}

void PlayerObject::moveLeft(sf::RenderWindow *super) {
    if(!sf::Keyboard::isKeyPressed(up)&&!sf::Keyboard::isKeyPressed(down)&&sf::Keyboard::isKeyPressed(left)&&!sf::Keyboard::isKeyPressed(right)){
        mainIterator++;

        if(mainIterator==100) {
            //super->clear();
            leftAnymation.setPosX(posX);
            leftAnymation.setPosY(posY);
            posX -= 1;

            leftAnymation.animate(super, true);
            mainIterator=0;
        }
        leftAnymation.draw(super);
    }



}

void PlayerObject::moveRight(sf::RenderWindow *super) {
    if(!sf::Keyboard::isKeyPressed(up)&&!sf::Keyboard::isKeyPressed(down)&&!sf::Keyboard::isKeyPressed(left)&&sf::Keyboard::isKeyPressed(right)){
        mainIterator1++;

        if(mainIterator1==100) {
            //super->clear();

            rightAnymation.setPosX(posX);
            rightAnymation.setPosY(posY);
            posX=posX+1;

            rightAnymation.animate(super, true);

            mainIterator1=0;

        }
        rightAnymation.draw(super);
    }

       // rightAnymation.setPosX(posX);
        //rightAnymation.setPosY(posY);}


}

void PlayerObject::loadUp(std::string p1, std::string p2, std::string p3, std::string p4) {
    Point2D w(posX,posY);
    sf::Image a,b,c,d;
    upAnymation.setImg(p1);

    a.loadFromFile(p1);
    b.loadFromFile(p2);
    c.loadFromFile(p3);
    d.loadFromFile(p4);
    upAnymation.addImage(a,w);
    upAnymation.addImage(b,w);
    upAnymation.addImage(c,w);
    upAnymation.addImage(d,w);
    upAnymation.init();
}

void PlayerObject::loadDown(std::string p1, std::string p2, std::string p3, std::string p4) {
    Point2D w(posX,posY);
    sf::Image a,b,c,d;
    downAnymation.setImg(p1);

    a.loadFromFile(p1);
    b.loadFromFile(p2);
    c.loadFromFile(p3);
    d.loadFromFile(p4);
    downAnymation.addImage(a,w);
    downAnymation.addImage(b,w);
    downAnymation.addImage(c,w);
    downAnymation.addImage(d,w);
    downAnymation.init();
}

void PlayerObject::loadRight(std::string p1, std::string p2, std::string p3, std::string p4) {
    Point2D w(posX,posY);
    sf::Image a,b,c,d;
    rightAnymation.setImg(p1);

    a.loadFromFile(p1);
    b.loadFromFile(p2);
    c.loadFromFile(p3);
    d.loadFromFile(p4);
    rightAnymation.addImage(a,w);
    rightAnymation.addImage(b,w);
    rightAnymation.addImage(c,w);
    rightAnymation.addImage(d,w);
    rightAnymation.init();
}

void PlayerObject::loadLeft(std::string p1, std::string p2, std::string p3, std::string p4) {
    Point2D w(posX,posY);
    sf::Image a,b,c,d;
    leftAnymation.setImg(p1);

    a.loadFromFile(p1);
    b.loadFromFile(p2);
    c.loadFromFile(p3);
    d.loadFromFile(p4);
    leftAnymation.addImage(a,w);
    leftAnymation.addImage(b,w);
    leftAnymation.addImage(c,w);
    leftAnymation.addImage(d,w);
    leftAnymation.init();
}

void PlayerObject::setUpControl(sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key left,
                                sf::Keyboard::Key right) {
    this->up=up;
    this->down=down;
    this->left=left;
    this->right=right;
}
void PlayerObject::draw(sf::RenderWindow *parent) {
    if(!sf::Keyboard::isKeyPressed(up)&&!sf::Keyboard::isKeyPressed(down)&&!sf::Keyboard::isKeyPressed(left)&&!sf::Keyboard::isKeyPressed(right)){
        ts.update(img);
        painter.setTexture(ts);
        painter.setPosition(posX,posY);
        parent->draw(painter);
    }
}
