//
// Created by cezary on 15.11.2021.
//

#ifndef GKLAB_ANIMATEDOBJECT_H
#define GKLAB_ANIMATEDOBJECT_H
#include <SFML/Graphics.hpp>
/**
 * @class Klasa Abstrakcyjna zawierając metodę abstrkcyjne słuząca do animacji
 */
class  AnimatedObject{
public:
    /**
     *
     * @param parent Wskażnik na główne okno gry
     */
    virtual void  animate(sf::RenderWindow *parent,bool t);
};
#endif //GKLAB_ANIMATEDOBJECT_H
