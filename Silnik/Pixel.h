//
// Created by cezary on 15.11.2021.
//

#ifndef GKLAB_PIXEL_H
#define GKLAB_PIXEL_H
#include <SFML/Graphics.hpp>
class Pixel
{
public:
    sf::Color c;
    double x;
    double y;
    Pixel(double x,double  y,sf::Color c){
        this->x=x;
        this->y=y;
        this->c=c;
    }
    Pixel operator= (Pixel p){
       this->x=p.x;
       this->y=p.y;
       this->c=p.c;
    }
};
#endif //GKLAB_PIXEL_H
