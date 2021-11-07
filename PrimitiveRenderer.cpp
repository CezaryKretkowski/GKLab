//
// Created by cezary on 11.10.2021.
//
#include <iostream>
#include "PrimitiveRenderer.h"

void PrimitiveRenderer::drawCircle(sf::RenderWindow *parent, sf::Color color, float size, float x, float y) {
    sf::CircleShape shape(size);
    shape.setFillColor(color);
    shape.setPosition(x, y);
    parent->draw(shape);
}

void PrimitiveRenderer::drawTriangle(sf::RenderWindow *parent, sf::Color color, float size, float x, float y) {
    sf::CircleShape shape(size);
    shape.setPointCount(3);
    shape.setFillColor(color);
    shape.setPosition(x, y);
    parent->draw(shape);
}

void PrimitiveRenderer::drawRectangle(sf::RenderWindow *parent, sf::Color color, float size, float x, float y) {
    sf::RectangleShape shape(sf::Vector2f(100, 50));
    shape.setPosition(x, y);
    shape.setFillColor(color);
    parent->draw(shape);
}

void PrimitiveRenderer::drawOctagon(sf::RenderWindow *parent, sf::Color color, float size, float x, float y) {
    sf::CircleShape shape(size);
    shape.setPointCount(5);
    shape.setFillColor(color);
    shape.setPosition(x, y);
    parent->draw(shape);
}

void PrimitiveRenderer::drawPolygon(sf::RenderWindow *parent, sf::Color color, float size, float x, float y) {
    sf::ConvexShape shape(size);
    shape.setPointCount(5);
    shape.setPoint(0, sf::Vector2f(0.f, 10.f));
    shape.setPoint(1, sf::Vector2f(300.f, 50.f));
    shape.setPoint(3, sf::Vector2f(100.f, 190.f));
    shape.setPoint(2, sf::Vector2f(200.f, 60.f));
    shape.setPoint(4, sf::Vector2f(0.f, 20.f));
    shape.setFillColor(color);
    shape.setPosition(x, y);
    parent->draw(shape);
}

void PrimitiveRenderer::drawPiksel(sf::RenderWindow *parent, sf::Color color, float x, float y) {
    sf::Image view;
    view.create(1,1,color);
    sf::Texture t1;
    t1.create(1,1);
    t1.update(view);
    sf::Sprite sx;
    sx.setTexture(t1);
    sx.setPosition(x,y);
    parent->draw(sx);
}

void PrimitiveRenderer::drawLineMain(sf::RenderWindow *parent, sf::Color color, Point2D point1, Point2D point2) {
    Point2D delta;
    Point2D p1;
    Point2D p0;
    float h,s;
    int i,w;

    p0=point2;
    p1=point1;
    if(p0.getX()>p1.getX()){
        Point2D tmp=p0;
        p0=p1;
        p1=tmp;
    }
    if(p1.getY()>p0.getY())
        h=p1.getY()-p0.getY();
    else
        h=p0.getY()-p1.getY();

    s=p1.getX()-p0.getX();


    float y,m;
    delta.setY(p1.getY()-p0.getY());
    delta.setX(p1.getX()-p0.getX());
    if(s<h) {
        if(p0.getY()>p1.getY()){
            Point2D tmp=p0;
            p0=p1;
            p1=tmp;
        }
        i=(int)p0.getY();
        w=(int)p1.getY();
        m = delta.getX() / delta.getY();
        y=p0.getX();

        for(i;i<=w;i++) {
            this->drawPiksel(parent, color, y, (float ) i+0.5 );
            y+=m;

        }
    }
    else {
        i=(int)p0.getX();
        w=(int)p1.getX();
        m = delta.getY() / delta.getX();
        y=p0.getY();


;
        for(i;i<=w;i++) {
            this->drawPiksel(parent, color, (float) i, y + 0.5);
            y+=m;

        }
    }

}
