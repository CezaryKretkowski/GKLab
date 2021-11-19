//
// Created by cezary on 11.10.2021.
//

#ifndef GK_LAB_PRIMITIVERENDERER_H
#define GK_LAB_PRIMITIVERENDERER_H
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include <list>

class PrimitiveRenderer{
private:
public:
    void drawCircle(sf::RenderWindow *parent,sf::Color color, float size, float x=0, float y=0);
    void drawTriangle(sf::RenderWindow * parent, sf::Color color, float size, float x=0, float y=0);
    void drawRectangle(sf::RenderWindow * parent, sf::Color color, float size, float x=0, float y=0);
    void drawOctagon(sf::RenderWindow * parent, sf::Color color, float size, float x=0, float y=0);
    void drawPiksel(sf::RenderWindow * parent, sf::Color color, float x,float y);
    void drawSegment(sf::RenderWindow * parent, sf::Color color,std::list<Point2D> Points);
    void drawLineMain(sf::RenderWindow * parent, sf::Color color,Point2D p1,Point2D p2);
    void drawPolygon(sf::RenderWindow * parent, sf::Color color, float size, float x=0, float y=0);
    sf::Color getPixel(double x,double y,sf::RenderWindow* parent);
    void fileColor(sf::RenderWindow* parent,double x, double y,sf::Color fileColor);

};
#endif //GK_LAB_PRIMITIVERENDERER_H
