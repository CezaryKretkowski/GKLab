//
// Created by cezar on 18.10.2021.
//
//#include "PrimitiveRenderer.h"
#include "Point2D.h"


Point2D::Point2D(float x, float y){
    this->x=x;
    this->y=y;
}
float Point2D::getX() {
    return this->x;
}
float Point2D::getY(){
    return this->y;
}
void Point2D::setX(float x) {
    this->x=x;
}
void Point2D::setY(float y) {
    this->y=y;
}
//void Point2D::drawPoint(sf::RenderWindow *parent,sf::Color color){
   // PrimitiveRenderer render;
  //  render.drawPiksel(parent,color,this->x,this->y);
//}