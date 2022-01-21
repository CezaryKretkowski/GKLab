//
// Created by cezar on 25.11.2021.
//

#ifndef GKLAB_PLAYEROBJECT_H
#define GKLAB_PLAYEROBJECT_H
#include "SpriteObject.h"
#include "KeyListener.h"

class PlayerObject:public SpriteObject{
private:
    int mainIterator=0;
    int mainIterator1=0;
    int mainIterator2=0;
    int mainIterator3=0;
    sf::Keyboard::Key up;
    sf::Keyboard::Key down;
    sf::Keyboard::Key left;
    sf::Keyboard::Key right;
public:
    SpriteObject upAnymation;
    SpriteObject downAnymation;
    SpriteObject leftAnymation;
    SpriteObject rightAnymation;
    void setUpControl(sf::Keyboard::Key up,sf::Keyboard::Key down,sf::Keyboard::Key left,sf::Keyboard::Key right);
    void loadUp(std::string p1,std::string p2,std::string p3,std::string p4 );
    void loadDown(std::string p1,std::string p2,std::string p3,std::string p4 );
    void loadLeft(std::string p1,std::string p2,std::string p3,std::string p4 );
    void loadRight(std::string p1,std::string p2,std::string p3,std::string p4 );
    void moveUp(sf::RenderWindow *super);
    void moveDown(sf::RenderWindow *super);
    void moveLeft(sf::RenderWindow *super);
    void moveRight(sf::RenderWindow *super);
    void draw(sf::RenderWindow*parent)override;
};
#endif //GKLAB_PLAYEROBJECT_H
