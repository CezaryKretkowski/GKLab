//
// Created by cezary on 08.11.2021.
//
#include "LineSegment.h"

void LineSegment::Draw(sf::RenderWindow *parent, sf::Color color,bool sfml){
    if(sfml){

        sf::Vertex line[] =
                {
                        sf::Vertex(sf::Vector2f(getA().getX(), getA().getY())),
                        sf::Vertex(sf::Vector2f(getB().getX(), getB().getY()))
                };
        parent->draw(line,2,sf::Lines);
    }


}
