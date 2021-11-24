//
// Created by cezary on 11.10.2021.
//
#include <iostream>
#include "PrimitiveRenderer.h"
#include "Pixel.h"
#include <cmath>
#define PI 3.14159265

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
    view.create(2.0,2.0,color);
    sf::Texture t1;
    t1.create(2.0,2.0);
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


void PrimitiveRenderer::drawSegment(sf::RenderWindow *parent, sf::Color color, std::list<Point2D> ls) {
    std::list<Point2D>::iterator i,w;
    i=ls.begin();
    w=i++;
    while(w!=ls.end()&&i!=ls.end()){

        drawLineMain(parent,color,*i,*w);
        i++;
        w++;
    }
}
sf::Color PrimitiveRenderer::getPixel(double x, double y,sf::RenderWindow* parent) {
    //aa::RenderTexture r;
    parent->display();
    sf::Image img=parent->capture();
    auto color = img.getPixel(x,y);
    std::cout<<color.toInteger()<<std::endl;
    return color;
}
void PrimitiveRenderer::fileColor(sf::RenderWindow *parent,double x, double y,sf::Color fillColor) {
            std::list<Pixel> dsd;
            std::list<Pixel>::iterator i=dsd.begin();
            Pixel tmp(x,y, getPixel(x,y,parent));
            Pixel N(x,y, getPixel(x,y,parent));
            Pixel S(x,y, getPixel(x,y,parent));
            Pixel W(x,y,getPixel(x,y,parent));
            Pixel E(x,y, getPixel(x,y,parent));
            sf::Color backColor=getPixel(x,y,parent);

            dsd.push_front(tmp);
            while(!dsd.empty()){
            tmp=*dsd.begin();
            dsd.pop_front();
                if(tmp.c!=fillColor)
                {
                    tmp.c=fillColor;
                    drawPiksel(parent,tmp.c,tmp.x,tmp.y);
                    N.y-=1;
                    std::cout<<"MAgenta int "<<sf::Color::Magenta.toInteger()<<std::endl;
                    std::cout<<"loop ";
                    N.c= getPixel(N.x,N.y,parent);
                    S.y+=1;
                    std::cout<<"loop ";
                    S.c= getPixel(S.x,S.y,parent);
                    W.x-=1;
                    std::cout<<"loop ";
                    W.c= getPixel(W.x,W.y,parent);
                    E.x+=1;
                    std::cout<<"loop ";
                    E.c= getPixel(E.x,E.y,parent);
                    if(N.c==backColor||N.c==fillColor)
                    dsd.push_front(N);
                    if(S.c==backColor||S.c==fillColor)
                    dsd.push_front(S);
                    if(W.c==backColor||W.c==fillColor)
                    dsd.push_front(W);
                    if(E.c==backColor||E.c==fillColor)
                    dsd.push_front(E);

                }


            }
}
void PrimitiveRenderer::drawCircleAlg(sf::RenderWindow *parent, double x, double y,double r, sf::Color fileColor) {
    double i=0;
    for(i;i<(2*PI)/4;i+=0.01){
        double x1,y1;
        x1=x+r* cos(i);
        y1=y+r* sin(i);
        drawPiksel(parent,fileColor,x1,y1);
        drawPiksel(parent,fileColor,x-r* cos(i),y-r* sin(i));
        drawPiksel(parent,fileColor,x-r* cos(i),y+r* sin(i));
        drawPiksel(parent,fileColor,x+r* cos(i),y-r* sin(i));
    }
}
void PrimitiveRenderer::drawElispeAlg(sf::RenderWindow *parent, double x, double y, double r1, double r2,
                                      sf::Color fileColor) {
    double i=0;
    for(i;i<(2*PI)/4;i+=0.01){
        double x1,y1;
        x1=x+r1* cos(i);
        y1=y+r2* sin(i);
        drawPiksel(parent,fileColor,x1,y1);
        drawPiksel(parent,fileColor,x-r1* cos(i),y-r2* sin(i));
        drawPiksel(parent,fileColor,x-r1* cos(i),y+r2* sin(i));
        drawPiksel(parent,fileColor,x+r1* cos(i),y-r2* sin(i));
    }
}
