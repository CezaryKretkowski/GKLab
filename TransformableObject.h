//
// Created by cezar on 23.11.2021.
//

#ifndef GKLAB_TRANSFORMABLEOBJECT_H
#define GKLAB_TRANSFORMABLEOBJECT_H
#include "Point2D.h"
#include <SFML/Graphics.hpp>
class TransformableObject{
protected:
    virtual void translate(Point2D t,sf::RenderWindow *super);
    virtual void rotate(float angle,sf::RenderWindow *super);
    virtual void scale();
};
#endif //GKLAB_TRANSFORMABLEOBJECT_H
