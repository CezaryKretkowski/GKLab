//
// Created by cezary on 15.11.2021.
//

#ifndef GKLAB_ANIMATEDOBJECT_H
#define GKLAB_ANIMATEDOBJECT_H
#include <SFML/Graphics.hpp>
class  AnimatedObject{
public:
    virtual  animate(sf::RenderWindow *parent);
};
#endif //GKLAB_ANIMATEDOBJECT_H
