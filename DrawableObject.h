//
// Created by cezary on 15.11.2021.
//

#ifndef GKLAB_DRAWABLEOBJECT_H
#define GKLAB_DRAWABLEOBJECT_H
#include <SFML/Graphics.hpp>
class DrawableObject{
private:
    sf::Texture ts;
    sf::Image img;
    sf::Sprite painter;
    double posX;
    double posY;
public:
    void setImg(std::string path);
    virtual void draw(sf::RenderWindow *super);
    void setPosX(double x){posX=x;};
    void setPosY(double y){posY=y;};
    double getPosX(){return posX;}
    double getPosY(){return posY;}
};
#endif //GKLAB_DRAWABLEOBJECT_H
