//
// Created by cezar on 23.11.2021.
//

#ifndef GKLAB_LINESHAPE_H
#define GKLAB_LINESHAPE_H
#include "ShapObject.h"
#include "Point2D.h"
class LineShape :public ShapObject{
private:
    Point2D p1;
    Point2D p2;
public:
    LineShape(Point2D p1,Point2D p2);
    virtual void draw(sf::RenderWindow *super)override;
    virtual void translate(Point2D,sf::RenderWindow *super)override;
    virtual void rotate(float angle,sf::RenderWindow *super)override;
};

#endif //GKLAB_LINESHAPE_H
