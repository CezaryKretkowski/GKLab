//
// Created by cezary on 08.11.2021.
//
#include "LineSegment.h"
#include "PrimitiveRenderer.h"
LineSegment::LineSegment(Point2D a, Point2D b) {
    this->a=a;
    this->b=b;
}
void LineSegment::Draw(sf::RenderWindow *parent, sf::Color color,bool sfml){
    PrimitiveRenderer render;
    if(sfml){

        sf::Vertex line[] =
                {
                        sf::Vertex(sf::Vector2f(getA().getX(), getA().getY())),
                        sf::Vertex(sf::Vector2f(getB().getX(), getB().getY()))
                };
        line[0].color=color;
        line[1].color=color;
        parent->draw(line,2,sf::Lines);
    }
    else{
        render.drawLineMain(parent,color,a,b);
    }


}
