//
// Created by cezar on 23.11.2021.
//
#include "LineShape.h"
#include <cmath>
LineShape::LineShape(Point2D p1, Point2D p2) {
    this->p1=p1;
    this->p2=p2;
}
void LineShape::draw(sf::RenderWindow *super) {
    this->getRenderer()->drawLineMain(super,sf::Color::Magenta,p1,p2);
}
void  LineShape::translate(Point2D t, sf::RenderWindow *super) {
    p1.setX(this->p1.getX()+t.getX());
    p1.setY(this->p1.getY()+t.getY());
    p2.setX(this->p2.getX()+t.getX());
    p2.setY(this->p2.getY()+t.getY());
    draw(super);
}
void LineShape::rotate(float angle, sf::RenderWindow *super) {
    p1.setX(800+((p1.getX()-800)* cos(angle))-((p1.getY()-600)* sin(angle)));
    p1.setY(600+((p1.getX()-600)* sin(angle))+((p1.getY()-600)* cos(angle)));
    p2.setX(800+((p2.getX()-800)* cos(angle))-((p2.getY()-600)* sin(angle)));
    p2.setY(600+((p2.getX()-600)* sin(angle))+((p2.getY()-600)* cos(angle)));
    draw(super);
}

