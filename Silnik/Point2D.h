//
// Created by cezar on 18.10.2021.
//

#ifndef GK_LAB_POINT2D_H
#define GK_LAB_POINT2D_H
class Point2D{
private:
    float x;
    float y;
public:
    Point2D(float x=0,float y=0);
    void setX(float x);
    void setY(float x);
    float getX();
    float getY();
    //void drawPoint(sf::RenderWindow *parent,sf::Color color=sf::Color::White);
    Point2D operator=(Point2D p){
        this->x=p.x;
        this->y=p.y;
    }

};
#endif //GK_LAB_POINT2D_H
