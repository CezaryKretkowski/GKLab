//
// Created by cezary on 08.11.2021.
//

#ifndef GKLAB_LINESEGMENT_H
#define GKLAB_LINESEGMENT_H
#include <SFML/Graphics.hpp>
#include "Point2D.h"
class LineSegment{
public:
    Point2D a;
    Point2D b;
public:
    LineSegment(Point2D a,Point2D b);
    Point2D getA(){return a;};
    Point2D getB(){return b;};
    void setA(Point2D a);
    void setB(Point2D b);
    void Draw(sf::RenderWindow *parent, sf::Color color,bool sfml);
};
#endif //GKLAB_LINESEGMENT_H
